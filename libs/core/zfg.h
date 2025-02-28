#ifndef ZFG_H
#define ZFG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../collections/vector.h"

#define MAX_CONTENT_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} ZfgParameter;

typedef struct {
    ZfgParameter *parameters;
    size_t parameters_count;
} ZfgConfig;

ZfgConfig zfg_parse_config(const char *filename) {
    ZfgConfig result = {0};
    char *content = malloc(MAX_CONTENT_LENGTH);
    if (!content) {
        fprintf(stderr, "ERROR: Memory allocation failed\n");
        exit(1);
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: Failed to open file: %s\n", filename);
        free(content);
        exit(1);
    }

    size_t read_size = fread(content, 1, MAX_CONTENT_LENGTH - 1, fp);
    content[read_size] = '\0'; 
    fclose(fp);

    Vector rvec = split_to_vector(content, "\n");
    result.parameters = malloc(vector_len(&rvec) * sizeof(ZfgParameter));
    if (!result.parameters) {
        fprintf(stderr, "ERROR: Memory allocation failed for parameters\n");
        vector_free(&rvec);
        free(content);
        exit(1);
    }

    VECTOR_FOR_EACH(char *, line, &rvec) {
        if (!*line || **line == '\0') continue;
        Vector lvec = split_to_vector(*line, "=");
        if (vector_len(&lvec) < 2) {
            fprintf(stderr, "ERROR: Invalid config line: %s\n", *line);
            vector_free(&lvec);
            continue;
        }

        result.parameters[result.parameters_count].key = strdup(vector_get_str(&lvec, 0));
        result.parameters[result.parameters_count].value = strdup(vector_get_str(&lvec, 1));
        result.parameters_count++;

        vector_free(&lvec);
    }

    vector_free(&rvec);
    free(content);
    return result;
}

void zfg_free_config(ZfgConfig *config) {
    for (size_t i = 0; i < config->parameters_count; i++) {
        free(config->parameters[i].key);
        free(config->parameters[i].value);
    }
    free(config->parameters);
    config->parameters = NULL;
    config->parameters_count = 0;
}

const char *zfg_get_value(const ZfgConfig *config, const char *key) {
    for (size_t i = 0; i < config->parameters_count; i++) {
        if (strcmp(config->parameters[i].key, key) == 0) {
            return config->parameters[i].value;
        }
    }
    return NULL;
}

void zfg_set_value(ZfgConfig *config, const char *key, const char *value) {
    for (size_t i = 0; i < config->parameters_count; i++) {
        if (strcmp(config->parameters[i].key, key) == 0) {
            free(config->parameters[i].value);
            config->parameters[i].value = strdup(value);
            return;
        }
    }
    config->parameters = realloc(config->parameters, (config->parameters_count + 1) * sizeof(ZfgParameter));
    if (!config->parameters) {
        fprintf(stderr, "ERROR: Memory allocation failed for new parameter\n");
        exit(1);
    }

    config->parameters[config->parameters_count].key = strdup(key);
    config->parameters[config->parameters_count].value = strdup(value);
    config->parameters_count++;
}

void zfg_export_config(const ZfgConfig *config, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "ERROR: Failed to open file for writing: %s\n", filename);
        return;
    }

    for (size_t i = 0; i < config->parameters_count; i++) {
        fprintf(fp, "%s=%s\n", config->parameters[i].key, config->parameters[i].value);
    }

    fclose(fp);
}

#endif // ZFG_H

