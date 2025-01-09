#include <stdio.h>
#include <string.h>
#include "libs/collections/hashmap.h"

int main() {
    // Creates an hashmap
    HashMap map;
    hashmap_init(&map, 0);

    // Pushing a key-value pair (can have every type)
    int age = 25;
    hashmap_set(&map, "age", &age, sizeof(age));

    // Get the values
    int *retrieved_age = (int *)hashmap_get(&map, "age");
    const char **retrieved_name = (const char **)hashmap_get(&map, "name");

    if (retrieved_age) {
        printf("Age: %d\n", *retrieved_age);
    }
    if (retrieved_name) {
        printf("Name: %s\n", *retrieved_name);
    }

    // Remove an key (with the value)
    if (hashmap_remove(&map, "age")) {
        printf("Age key-value pair removed\n");
    }

    // Free the hashmap resources
    hashmap_free(&map);
    return 0;
}
