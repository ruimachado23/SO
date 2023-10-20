#!/bin/bash

read -p "Por favor, insira o primeiro número: " num1
read -p "Agora, insira o segundo número: " num2

comparar_numeros() {
    if [ $1 -eq $2 ]; then
        echo "Os números são iguais."
    elif [ $1 -gt $2 ]; then
        echo "O primeiro número ($1) é maior."
    else
        echo "O segundo número ($2) é maior."
    fi
}

comparar_numeros "$num1" "$num2"
