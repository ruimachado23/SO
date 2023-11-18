#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Número incorreto de argumentos. Use como args: <limite mínimo> <limite máximo>\n");
        return EXIT_FAILURE;
    }

    int min = atoi(argv[1]);
    int max = atoi(argv[2]);

    if (min >= max) {
        fprintf(stderr, "O limite mínimo deve ser menor que o limite máximo.\n");
        return EXIT_FAILURE;
    }

    int key = min + rand() % (max - min + 1);  // Generate a random number within the range
    int guess = -1;

    while (guess != key) {
        printf("Enter a guess: ");
        scanf("%d", &guess);  // Use &guess to store the input
        if (guess > key) printf("Menor\n");
        else if (guess < key) printf("Maior\n");
    }

    printf("Parabéns!\n");

    return EXIT_SUCCESS;
}
