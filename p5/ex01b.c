#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Número incorreto de argumentos. Por favor, forneça exatamente dois argumentos.\n");
        return EXIT_FAILURE; // Valor de erro
    }

    char *arg1 = argv[1];
    char *arg2 = argv[2];

    printf("Argumento 1: \"%s\"\n", arg1);
    printf("Argumento 2: \"%s\"\n", arg2);


    return EXIT_SUCCESS; // Programa terminado com sucesso
}
