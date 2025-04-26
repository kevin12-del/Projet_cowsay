#!/usr/bin/env bash
# cow_primaryschool.sh
# Usage: ./cow_primaryschool.sh <n>
# Prononce les chiffres de 1 à n.

if [ -z "$1" ] || ! [[ "$1" =~ ^[0-9]+$ ]]; then
  echo "Usage: $0 <nombre_entier>"
  exit 1
fi

n=$1
for ((i=1; i<=n; i++)); do
  clear
  cowsay "$i"
  sleep 1
done