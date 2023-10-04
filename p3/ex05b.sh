#!/bin/bash
if [ $# -ne 1 ]; then
    echo "Erro: Este script requer exatamente um argumento."
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Erro: O argumento não é um diretório válido."
    exit 1
fi

for f in $1/*; do
file "$f"
done