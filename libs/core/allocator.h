// This is a simple linear allocator
// it cannot be freed | here is a big plus: it frees after runtime
// a minus is it can be only allocated up to 2gb | U can change the source code but only up to 4 gb
#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#define ARENA_CAPACITY 1024 * 1024 * 2

// recommendation use it like this
// static AArena arena = {0};
// and somewhere in the code
// void *chunk = aarena_alloc(&arena, bytes);
// memcpy(chunk, data_here, data_count);

typedef struct {
    char buffer[ARENA_CAPACITY];
    size_t size;
} AArena; // Allocator Arena

void *aarena_alloc(AArena *arena, size_t size) {
    if (arena->size + size > ARENA_CAPACITY) {
        return NULL;
    }
    void *ptr = &arena->buffer[arena->size];
    arena->size += size;
    return ptr;
}

// Not frees the arena allows to reset it
void aarena_reset(AArena *arena) {
    arena->size = 0;
}

#endif // ALLOCATOR_H



