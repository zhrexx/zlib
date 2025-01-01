#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

#define DEFAULT_SOURCE_DIR "libs"
#define DEFAULT_DEST_DIR "/usr/include/zlib/"

void create_dir(const char *path) {
    char temp[256];
    char *pos = NULL;

    strncpy(temp, path, sizeof(temp));
    temp[sizeof(temp) - 1] = '\0';

    for (pos = temp + 1; *pos; pos++) {
        if (*pos == '/') {
            *pos = '\0';
            mkdir(temp, 0755);
            *pos = '/';
        }
    }
    mkdir(temp, 0755);
}

void copy_file(const char *src_path, const char *dest_path) {
    FILE *src = fopen(src_path, "rb");
    if (!src) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest = fopen(dest_path, "wb");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void copy_dir(const char *src, const char *dest) {
    DIR *dir = opendir(src);
    if (!dir) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[512];
        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);

        char dest_path[512];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (entry->d_type == DT_DIR) {
            create_dir(dest_path);
            copy_dir(src_path, dest_path);
        } else if (entry->d_type == DT_REG) {
            copy_file(src_path, dest_path);
            printf("+ %s\n", dest_path + strlen(dest) - strlen(entry->d_name));
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *source_dir = DEFAULT_SOURCE_DIR;
    char dest_dir[512] = DEFAULT_DEST_DIR;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            strncpy(dest_dir, argv[++i], sizeof(dest_dir) - 1);
            dest_dir[sizeof(dest_dir) - 1] = '\0';
        } else if (strcmp(argv[i], "--user") == 0) {
            snprintf(dest_dir, sizeof(dest_dir), "%s/.local/include/zlib/", getenv("HOME"));
        }
    }

    create_dir(dest_dir);
    copy_dir(source_dir, dest_dir);

    printf("Installation completed successfully.\n");
    return 0;
}
