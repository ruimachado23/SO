#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define MAX_LINE_LENGTH 50

int compareInts(const void *px1, const void *px2) {
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return (x1 < x2) ? -1 : (x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int numbers[MAX_NUMBERS];
    char line[MAX_LINE_LENGTH];
    int numSize = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) && numSize < MAX_NUMBERS) {
        numbers[numSize++] = atoi(line);
    }

    fclose(file);

    qsort(numbers, numSize, sizeof(int), compareInts);

    for (int i = 0; i < numSize; i++) {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
