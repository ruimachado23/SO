#!/bin/bash

# Verifica se foram passados dois argumentos
if [ $# -ne 2 ]; then
    echo "Por favor, forneça dois números como argumentos."
    exit 1
fi

comparar_numeros() {
    if [ $1 -eq $2 ]; then
        echo "Os números são iguais."
    elif [ $1 -gt $2 ]; then
        echo "O primeiro número ($1) é maior."
    else
        echo "O segundo número ($2) é maior."
    fi
}

comparar_numeros "$1" "$2"

