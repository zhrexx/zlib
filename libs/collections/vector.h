// ========================================================================================>
// ZHRXXgroup Project 🚀 - ZLib
// File: collections/vector.h
// Author(s): ZHRXXgroup
// Version: 1
// ========================================================================================>

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} Vector;


void vector_init(Vector *vector, size_t initial_capacity, size_t element_size);
void vector_resize(Vector *vector, size_t new_capacity);
void vector_push(Vector *vector, const void *value);
void *vector_get(Vector *vector, size_t index);
void vector_set(Vector *vector, size_t index, const void *value);
bool vector_contains(Vector *vector, const void *value);
void vector_remove(Vector *vector, size_t index);
ssize_t vector_find(Vector *vector, const void *value);
void vector_compress(Vector *vector);
void vector_copy(Vector *dest, const Vector *src);
void vector_free(Vector *vector);

//----------------------------------------------//
//----------------------------------------------//

void vector_init(Vector *vector, size_t initial_capacity, size_t element_size) {
    if (initial_capacity == 0) initial_capacity = 1;
    vector->data = malloc(initial_capacity * element_size);
    if (!vector->data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    vector->size = 0;
    vector->capacity = initial_capacity;
    vector->element_size = element_size;
}

void vector_resize(Vector *vector, size_t new_capacity) {
    if (new_capacity == 0) new_capacity = 1;
    void *new_data = realloc(vector->data, new_capacity * vector->element_size);
    if (!new_data) {
        fprintf(stderr, "Failed to reallocate memory\n");
        exit(EXIT_FAILURE);
    }
    vector->data = new_data;
    vector->capacity = new_capacity;
}

void vector_push(Vector *vector, const void *value) {
    if (vector->size == vector->capacity) {
        vector_resize(vector, vector->capacity == 0 ? 1 : vector->capacity * 2);
    }
    void *target = (char *)vector->data + (vector->size * vector->element_size);
    memcpy(target, value, vector->element_size);
    vector->size++;
}

// ! *(type *) you need to cast to get result
void *vector_get(Vector *vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return (char *)vector->data + (index * vector->element_size);
}

void vector_set(Vector *vector, size_t index, const void *value) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    void *target = (char *)vector->data + (index * vector->element_size);
    memcpy(target, value, vector->element_size);
}

bool vector_contains(Vector *vector, const void *value) {
    for (size_t i = 0; i < vector->size; i++) {
        void *current_element = (char *)vector->data + (i * vector->element_size);

        if (vector->element_size == sizeof(char *)) {
            const char *str1 = *(const char **)current_element;
            const char *str2 = (const char *)value;
            if (strcmp(str1, str2) == 0) {
                return true;
            }
        } else {
            if (memcmp(current_element, value, vector->element_size) == 0) {
                return true;
            }
        }
    }
    return false;
}

void vector_remove(Vector *vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    void *target = (char *)vector->data + (index * vector->element_size);
    void *next_element = (char *)vector->data + ((index + 1) * vector->element_size);
    memmove(target, next_element, (vector->size - index - 1) * vector->element_size);
    vector->size--;
}

#define VECTOR_FOR_EACH(type, element, vector) \
    for (type *element = (type *)(vector)->data; \
         (char *)element < (char *)(vector)->data + (vector)->size * (vector)->element_size; \
         element++)

ssize_t vector_find(Vector *vector, const void *value) {
    for (size_t i = 0; i < vector->size; i++) {
        void *current_element = (char *)vector->data + (i * vector->element_size);
        if (memcmp(current_element, value, vector->element_size) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}

void vector_compress(Vector *vector) {
	if (vector->capacity > vector->size) {
        vector_resize(vector, vector->size);
    }
}


void vector_copy(Vector *dest, const Vector *src) {
    vector_init(dest, src->capacity, src->element_size);
    memcpy(dest->data, src->data, src->size * src->element_size);
    dest->size = src->size;
}


void vector_free(Vector *vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->element_size = 0;
}

size_t vector_len(Vector *vector) {
    return vector->size;
}

void *vector_pop(Vector *vector) {
    if (vector->size == 0) {
        fprintf(stderr, "Vector is empty\n");
        exit(EXIT_FAILURE);
    }

    void *last_element = vector_get(vector, vector->size - 1);
    vector_remove(vector, vector->size - 1);

    return last_element;
}




// Useful stuff
Vector parse_pargs(int argc, char **argv) {
    Vector pargs_vector;
    vector_init(&pargs_vector, 3, sizeof(char *));
    for (int i = 0; i < argc; i++) {
	    char *arg = strdup(argv[i]);
        vector_push(&pargs_vector, &arg);
    }

    return pargs_vector;
}


Vector split_to_vector(const char* src, const char* delimiter) {
    char* src_copy = strdup(src);
    char* token;
    Vector result;
    vector_init(&result, 10, sizeof(char *));
	
    token = strtok(src_copy, delimiter);
    while (token != NULL) {
        vector_push(&result, strdup(token));
        token = strtok(NULL, delimiter);
    }

    free(src_copy);
    vector_compress(&result);
    return result;
}


char *vector_get_str(Vector *vector, size_t index) {
    void *pointer = vector_get(vector, index);
    return *(char **)pointer;
}

int vector_get_int(Vector *vector, size_t index) {
    void *pointer = vector_get(vector, index);
    return *(int *)pointer;
}



#endif

