#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Número incorreto de argumentos. Use: ./calculadora <número> <operador> <número>\n");
        return EXIT_FAILURE; // Valor de erro
    }

    char *endptr1, *endptr2;
    double num1 = strtod(argv[1], &endptr1);
    char operador = argv[2][0]; // Obtem o primeiro caractere do operador
    double num2 = strtod(argv[3], &endptr2);

    if (*endptr1 != '\0' || *endptr2 != '\0') {
        fprintf(stderr, "Argumentos inválidos. Forneça números de ponto flutuante válidos.\n");
        return EXIT_FAILURE;
    }

    double resultado = 0.0;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case 'x':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 == 0.0) {
                fprintf(stderr, "Erro: Divisão por zero não é permitida.\n");
                return EXIT_FAILURE;
            }
            resultado = num1 / num2;
            break;
        case 'p':
            resultado = pow(num1, num2);
            break;
        default:
            fprintf(stderr, "Operador inválido. Use '+', '-', 'x', '/', ou 'p'.\n");
            return EXIT_FAILURE;
    }

    printf("Resultado: %lf\n", resultado);

    return EXIT_SUCCESS; // Programa terminado com sucesso
}
