#include <stdio.h>
#include <stdlib.h>

int compareInts(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int count = 0, temp;
    while (fscanf(file, "%d", &temp) == 1) {
        count++;
    }

    rewind(file);

    int *numbers = malloc(count * sizeof(int));

    for (int i = 0; i < count && fscanf(file, "%d", &numbers[i]) == 1; i++);

    fclose(file);

    qsort(numbers, count, sizeof(int), compareInts);

    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
    return EXIT_SUCCESS;
}
