#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listDir(const char *dirname) {
    DIR *dp;
    struct dirent *dent;
    char path[1024];

    dp = opendir(dirname);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((dent = readdir(dp)) != NULL) {
        if (dent->d_name[0] != '.') { // Do not list hidden dirs/files
            snprintf(path, sizeof(path), "%s/%s", dirname, dent->d_name);
            if (dent->d_type == DT_DIR) {
                printf("d %s\n", path);
                listDir(path); // Recursive call for subdirectory
            } else if (dent->d_type == DT_REG) {
                printf("  %s\n", path);
            } else {
                printf("? %s\n", path); // Unknown file type
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s base_directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    return EXIT_SUCCESS;
}
