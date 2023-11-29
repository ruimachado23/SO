#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

int compareInts(const void *px1, const void *px2) {
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return (x1 < x2) ? -1 : (x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[]) {

    FILE *file = fopen(argv[1], "r");

    int numbers[MAX_NUMBERS];
    int numSize = 0;

    while (numSize < MAX_NUMBERS && fscanf(file, "%d", &numbers[numSize]) == 1) {
        numSize++;
    }

    qsort(numbers, numSize, sizeof(int), compareInts);

    printf("Sorted numbers: \n");
    for (int i = 0; i < numSize; i++) {
        printf("%d\n", numbers[i]);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
