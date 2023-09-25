#!/bin/bash

# Verifica se foi fornecido o nome do arquivo como argumento
if [ $# -ne 1 ]; then
  echo "Uso: $0 <nome-do-arquivo>"
  exit 1
fi

nome_arquivo="$1"

# Verifica se o arquivo especificado existe
if [ -e "$nome_arquivo" ]; then
  codigo_saida=$(file "$nome_arquivo" 2>&1)
  echo "Código de Saída do 'file' para '$nome_arquivo': $?"
  echo "Resultado do 'file' para '$nome_arquivo':"
  echo "$codigo_saida"
else
  echo "O arquivo '$nome_arquivo' não existe."
  exit 2
fi
