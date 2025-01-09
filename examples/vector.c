#include <stdio.h>
#include <stdbool.h>
#include "libs/collections/vector.h"


int main(int argc, char **argv) {
    // Parsing PArgs to vector
    Vector args = parse_pargs(argc, argv);

    // Iterate trough vector and print it
    // NOTE: you become a pointer to arg you need to dereference it
    VECTOR_FOR_EACH(char *, arg, &args) {
        printf("%s\n", *arg);
    }

    // Creates an vector
    // Prototype: void vector_init(Vector *vector, size_t initial_capacity, size_t element_size)
    Vector vector;
    vector_init(&vector, 10, sizeof(int));

    // Pushing an value to vector
    int example_value = 10;
    vector_push(&vector, &example_value);

    // Getting an value from vector
    // Prototype: void *vector_get(Vector *vector, size_t index);
    // You must dereference it or use our builtin methods
    int value = *(int *)vector_get(&vector, 0);
    // For int you need to use: vector_get_int(&vector, 0);
    // For strings you need to use: vector_get_str(&vector, 0);

    // Setting an value at decided index in vector (only for rewriting exiting data)
    // Prototype: void vector_set(Vector *vector, size_t index, const void *value);
    int example_value2 = 20;
    vector_set(&vector, 0, &example_value2);

    // To check if a vector contains an value
    // Prototype: bool vector_contains(Vector *vector, const void *value);
    bool contains = vector_contains(&vector, &example_value2);

    // To remove an element from vector at desired index
    // Prototype: void vector_remove(Vector *vector, size_t index);
    vector_remove(&vector, 0);

    VECTOR_FOR_EACH(int, value, &vector) {
        printf("%d\n", *value);
        if (value) {
            printf("Existing, it dont worked");
        }
    }

    // To find an element (e.g with value 10)
    // Prototype: int vector_find(Vector *vector, const void *value);
    int index = vector_find(&vector, &example_value); // im using example_value but it also works with other values

    // To split an string by delimiter
    // Prototype: Vector split_to_vector(const char* src, const char* delimiter);
    Vector split = split_to_vector("Hello World", " ");

    // More methods are available at the header file

    // at program end you need to free it
    vector_free(&args);
    return 0;
}

