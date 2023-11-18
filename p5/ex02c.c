#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *username;

    username = getenv("NEWUSER");
    if (username != NULL) {
        printf("This program is being executed by %s\n", username);
    } else {
        printf("ERROR: NEWUSER not defined\n");
        return EXIT_FAILURE;
    }

    char combined[100] = ""; 
    for (int i = 1; i < argc; i++) {
        strncat(combined, argv[i], sizeof(combined));
    }

    printf("%s\n", combined);

    return EXIT_SUCCESS;
}


