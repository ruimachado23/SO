#!/bin/bash

# Brace Expansion
echo {1..9}
echo {0,1}{0..9}

for i in 1 2 3 4 5 6 7 8 9; do
  touch "$1${i}.dat"
done

echo "Arquivos criados:"
ls $1*.dat
