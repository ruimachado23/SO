#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Número incorreto de argumentos. Use como args: <número> <operador> <número>\n");
        return EXIT_FAILURE; // Valor de erro
    }

    double num1 = atof(argv[1]);
    char operador = argv[2][0]; // Obtem o primeiro caractere do operador
    double num2 = atof(argv[3]);

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
