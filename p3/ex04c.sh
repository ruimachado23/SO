#!/bin/bash
# Script para validar argumentos

# Verifica se o número de argumentos é igual a 2
if [ $# -ne 2 ]; then
    echo "Erro: Este script requer exatamente dois argumentos."
    exit 1
fi

# Valida o primeiro argumento (deve ser um número entre 0 e 99)
case $1 in
    [0-9]|[0-9][0-9])
        echo "O primeiro argumento é válido: $1"
        ;;
    *)
        echo "Erro: O primeiro argumento deve ser um número entre 0 e 99."
        exit 1
        ;;
esac

# Valida o segundo argumento (deve começar com 'sec')
case $2 in
    sec*)
        echo "O segundo argumento é válido: $2"
        ;;
    *)
        echo "Erro: O segundo argumento deve começar com 'sec'."
        exit 1
        ;;
esac

# Se ambos os argumentos forem válidos, exibe uma mensagem de sucesso
echo "Argumentos válidos: $1 e $2"
