// Sorry for naming i taken this code from my OrtaVM
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef enum {
    WINT,
    WFLOAT,
    WCHARP, 
    WCHAR,
    WPOINTER,
    WBOOL,
} WordType;

typedef struct {
    void *value;
    WordType type;
} Word;

Word word_create(void *value, WordType type) {
    Word result = {0};
    result.value = value; 
    result.type = type;
    return result;
}

typedef struct {
    Word *stack;
    size_t count;
    size_t capacity;
} XStack;

XStack xstack_create(size_t capacity) {
    XStack x = {0};
    x.stack = malloc(sizeof(Word) * capacity);
    x.capacity = capacity;
    x.count = 0;
    return x;
}

int xstack_push(XStack *stack, Word w) {
    if (stack->count >= stack->capacity) {
        return 0;
    }
    stack->stack[stack->count++] = w;
    return 1;
}

Word xstack_pop(XStack *stack) {
    Word w;
    if (stack->count == 0) {
        return word_create(NULL, WPOINTER);
    } else {
        w = stack->stack[--stack->count];
    }
    return w;
}

Word xstack_peek(XStack *stack, size_t offset) {
    if (offset >= stack->count) {
        return word_create(NULL, WPOINTER);
    }
    return stack->stack[stack->count - 1 - offset];
}

void xstack_free(XStack *stack) {
    free(stack->stack);
}


#endif // STACK_H
