#!/bin/bash

# Verifica se o número correto de argumentos foi fornecido
if [ $# -ne 1 ]; then
    echo "Uso: $0 <arquivo_de_entrada>"
    exit 1
fi

# Verifica se o arquivo de entrada existe
if [ ! -f "$1" ]; then
    echo "O arquivo de entrada não existe."
    exit 1
fi

# Verifica se o arquivo de entrada está vazio
if [ ! -s "$1" ]; then
    echo "O arquivo de entrada está vazio."
    exit 1
fi

# Verifica se o arquivo de entrada contém apenas números
if ! grep -q '^[0-9]*$' "$1"; then
    echo "O arquivo de entrada contém caracteres que não são números."
    exit 1
fi

# Função para ordenar um array de números usando o algoritmo de ordenação por seleção
ordenar_por_selecao() {
    local -n arr=$1
    local n=${#arr[@]}

    for ((i = 0; i < n - 1; i++)); do
        local min_idx=$i
        for ((j = i + 1; j < n; j++)); do
            if ((arr[j] < arr[min_idx])); then
                min_idx=$j
            fi
        done
        # Troca o elemento mínimo com o elemento atual
        local temp=${arr[i]}
        arr[i]=${arr[min_idx]}
        arr[min_idx]=$temp
    done
}

# Lê os números do arquivo de entrada e armazena-os em um array
mapfile -t numbers < "$1"

# Chama a função para ordenar o array de números
ordenar_por_selecao numbers

# Imprime os números ordenados
for num in "${numbers[@]}"; do
    echo "$num"
done
