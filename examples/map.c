#include <stdio.h>
#include <stdbool.h>
#include "libs/collections/map.h"

int main(int argc, char **argv) {
    // Initialize a map with an initial capacity of 10
    Map map;
    map_init(&map, 10);

    // Set key-value pairs in the map
    int value1 = 42;
    map_push(&map, "key1", &value1, sizeof(value1));

    const char *value2 = "Hello, World!";
    map_push(&map, "key2", &value2, sizeof(value2));

    // Get and print values by key
    int *retrieved_value1 = (int *)map_get(&map, "key1");
    if (retrieved_value1) {
        printf("key1: %d\n", *retrieved_value1);
    }

    const char *retrieved_value2 = *(const char **)map_get(&map, "key2");
    if (retrieved_value2) {
        printf("key2: %s\n", retrieved_value2);
    }

    // Check if a key exists
    if (map_get(&map, "key1")) {
        printf("key1 exists in the map\n");
    }

    // Remove a key-value pair from the map
    if (map_remove(&map, "key2")) {
        printf("key2 removed from the map\n");
    }

    // Attempt to retrieve a removed key
    if (!map_get(&map, "key2")) {
        printf("key2 no longer exists in the map\n");
    }

    // Resize the map (optional if needed)
    map_resize(&map, 20);

    // Free the map when done
    map_free(&map);

    return 0;
}
