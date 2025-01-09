#ifndef BYTE_H
#define BYTE_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define BYTEARRAY_SIZE 524288

typedef uint8_t byte;

typedef struct {
    size_t size;
    size_t capacity;
    byte *data;
} bytearray;

bytearray bytearray_new(size_t capacity) {
    bytearray b;
    if (capacity == 0) {
        capacity = BYTEARRAY_SIZE;
    }
    b.size = 0;
    b.capacity = capacity;
    b.data = (byte *)malloc(sizeof(byte) * capacity);
    return b;
}

void bytearray_resize(bytearray *b, size_t new_capacity) {
    if (!b || !b->data) {
        return;
    }
    if (new_capacity == 0 || BYTEARRAY_SIZE / 2 < new_capacity) {
        new_capacity = BYTEARRAY_SIZE;
    }
    b->data = (byte *)realloc(b->data, sizeof(byte) * new_capacity);
    b->capacity = new_capacity;
}

void bytearray_free(bytearray *b) {
    if (b && b->data) {
        free(b->data);
        b->data = NULL;
        b->size = 0;
        b->capacity = 0;
    }
}

int bytearray_set(bytearray *b, size_t index, byte value) {
    if (!b || !b->data || index >= b->capacity) {
        return -1;
    }
    b->data[index] = value;
    if (index >= b->size) {
        b->size = index + 1;
    }
    return 0;
}

int bytearray_get(bytearray *b, size_t index, byte *value) {
    if (!b || !b->data || index >= b->size) {
        return -1;
    }
    *value = b->data[index];
    return 0;
}

byte char_to_byte(char c) {
    return (byte)c;
}

int bytearray_append(bytearray *b, byte value) {
    if (!b || !b->data) {
        return -1;
    }
    if (b->size >= b->capacity) {
        bytearray_resize(b, b->capacity*2);
    }
    b->data[b->size] = value;
    b->size++;
    return 0;
}

int bytearray_append_string(bytearray *b, char *str) {
    if (!b || !b->data || !str) {
        return -1;
    }
    size_t str_len = strlen(str);
    if (b->size + str_len >= b->capacity) {
        bytearray_resize(b, b->capacity*2);
    }
    memcpy(b->data + b->size, str, str_len);
    b->size += str_len;
    return 0;
}

void bytearray_print(bytearray *b) {
    if (!b || !b->data) {
        return;
    }
    for (size_t i = 0; i < b->size; i++) {
        printf("%c", b->data[i]);
    }
    printf("\n");
}

// if you wanna use it with c std function
char *bytearray_to_string(bytearray *b) {
    char *str = (char *)malloc(sizeof(char) * (b->size + 1));
    if (!b || !b->data || !str) {
        return "";
    }
    for (size_t i = 0; i < b->size; i++) {
        str[i] = b->data[i];
    }
    str[b->size++] = '\0';
    return str;
}

int bytearray_len(bytearray *b) {
    return b->size;
}

void bytearray_write_bytes(bytearray *b, FILE *fp) {
    if (!b || !b->data || !fp) {
        return;
    }
    size_t bytesWritten = fwrite(b->data, sizeof(byte), b->size, fp);
    if (bytesWritten != b->size) {
        perror("Error writing bytes to file");
    }
}



#endif // BYTE_H
