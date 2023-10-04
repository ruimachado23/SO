#!/bin/bash
# This script checks the existence of a file
[[ $# = 1 ]] || { echo "Erro: Indique ficheiro" >&2; exit 1; }
    echo "Checking..."
if [[ -f $1 ]] ; then
    echo "$1 existe."
else
    echo "$1 não existe"
fi

echo "...done."