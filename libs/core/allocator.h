#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <string.h>
#include <stdio.h>

typedef unsigned long uintptr_t;

#define ARENA_CAPACITY (1024 * 1024 * 2)

typedef struct {
    char buffer[ARENA_CAPACITY];
    size_t size;
} AArena;

static AArena global_arena = {0};

void *aarena_alloc(AArena *arena, size_t size) {
    if (arena->size + size > ARENA_CAPACITY) return NULL;
    void *ptr = &arena->buffer[arena->size];
    arena->size += size;
    return ptr;
}

void *aarena_alloc_aligned(AArena *arena, size_t size, size_t alignment) {
    uintptr_t current = (uintptr_t)&arena->buffer[arena->size];
    uintptr_t aligned = (current + (alignment - 1)) & ~(alignment - 1);
    size_t padding = aligned - current;
    if (arena->size + size + padding > ARENA_CAPACITY) return NULL;
    arena->size += padding;
    return aarena_alloc(arena, size);
}

void *aarena_calloc(AArena *arena, size_t count, size_t size) {
    size_t total = count * size;
    void *ptr = aarena_alloc(arena, total);
    if (ptr) memset(ptr, 0, total);
    return ptr;
}

void *aarena_realloc(AArena *arena, void *ptr, size_t old_size, size_t new_size) {
    if (!ptr) return aarena_alloc(arena, new_size);
    if ((char *)ptr + old_size == arena->buffer + arena->size) {
        if (new_size > old_size) {
            size_t diff = new_size - old_size;
            if (arena->size + diff > ARENA_CAPACITY) return NULL;
            arena->size += diff;
        } else {
            arena->size -= (old_size - new_size);
        }
        return ptr;
    } else {
        void *new_ptr = aarena_alloc(arena, new_size);
        if (!new_ptr) return NULL;
        size_t copy_size = old_size < new_size ? old_size : new_size;
        memcpy(new_ptr, ptr, copy_size);
        return new_ptr;
    }
}

void aarena_reset(AArena *arena) {
    arena->size = 0;
}

void aarena_free_to(AArena *arena, size_t marker) {
    if (marker <= arena->size) arena->size = marker;
}

size_t aarena_marker(AArena *arena) {
    return arena->size;
}

size_t aarena_remaining(AArena *arena) {
    return ARENA_CAPACITY - arena->size;
}

int aarena_contains(AArena *arena, void *ptr) {
    return (ptr >= (void*)arena->buffer) && (ptr < (void*)(arena->buffer + ARENA_CAPACITY));
}

char *aarena_strdup(AArena *arena, const char *str) {
    size_t len = strlen(str) + 1;
    char *dup = aarena_alloc(arena, len);
    if (dup) memcpy(dup, str, len);
    return dup;
}

void *aarena_memdup(AArena *arena, const void *src, size_t size) {
    void *dest = aarena_alloc(arena, size);
    if (dest) memcpy(dest, src, size);
    return dest;
}

void aarena_dump(AArena *arena) {
    printf("Arena dump:\nUsed: %zu bytes\nRemaining: %zu bytes\n", arena->size, aarena_remaining(arena));
}

typedef struct {
    char *start;
    size_t size;
    size_t offset;
} ARegion;

ARegion create_region(AArena *arena, size_t region_size) {
    ARegion region = {0};
    if (arena->size + region_size > ARENA_CAPACITY) {
        region.start = NULL;
        return region;
    }
    region.start = &arena->buffer[arena->size];
    region.size = region_size;
    region.offset = 0;
    arena->size += region_size;
    return region;
}

void *region_alloc(ARegion *region, size_t size) {
    if (region->offset + size > region->size) return NULL;
    void *ptr = region->start + region->offset;
    region->offset += size;
    return ptr;
}

void *region_alloc_aligned(ARegion *region, size_t size, size_t alignment) {
    uintptr_t current = (uintptr_t)(region->start + region->offset);
    uintptr_t aligned = (current + (alignment - 1)) & ~(alignment - 1);
    size_t padding = aligned - current;
    if (region->offset + size + padding > region->size) return NULL;
    region->offset += padding;
    return region_alloc(region, size);
}

void *region_calloc(ARegion *region, size_t count, size_t size) {
    size_t total = count * size;
    void *ptr = region_alloc(region, total);
    if (ptr) memset(ptr, 0, total);
    return ptr;
}

void region_reset(ARegion *region) {
    region->offset = 0;
}

void region_free_to(ARegion *region, size_t marker) {
    if (marker <= region->offset) region->offset = marker;
}

size_t region_marker(ARegion *region) {
    return region->offset;
}

size_t region_remaining(ARegion *region) {
    return region->size - region->offset;
}

int region_contains(ARegion *region, void *ptr) {
    return (ptr >= (void*)region->start) && (ptr < (void*)(region->start + region->size));
}

char *region_strdup(ARegion *region, const char *str) {
    size_t len = strlen(str) + 1;
    char *dup = region_alloc(region, len);
    if (dup) memcpy(dup, str, len);
    return dup;
}

void *region_memdup(ARegion *region, const void *src, size_t size) {
    void *dest = region_alloc(region, size);
    if (dest) memcpy(dest, src, size);
    return dest;
}

ARegion create_subregion(ARegion *parent, size_t subregion_size) {
    ARegion sub = {0};
    if (parent->offset + subregion_size > parent->size) {
        sub.start = NULL;
        return sub;
    }
    sub.start = parent->start + parent->offset;
    sub.size = subregion_size;
    sub.offset = 0;
    parent->offset += subregion_size;
    return sub;
}

void region_dump(ARegion *region) {
    printf("Region dump:\nRegion size: %zu bytes\nUsed: %zu bytes\nRemaining: %zu bytes\n", region->size, region->offset, region_remaining(region));
}

void *aarena_memcpy(void *dest, const void *src, size_t n) {
    return memcpy(dest, src, n);
}

void *aarena_memset(void *dest, int val, size_t n) {
    return memset(dest, val, n);
}

int aarena_memcmp(const void *s1, const void *s2, size_t n) {
    return memcmp(s1, s2, n);
}

#endif // ALLOCATOR_H

