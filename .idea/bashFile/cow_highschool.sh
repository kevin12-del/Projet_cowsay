#!/usr/bin/env bash
# cow_highschool.sh
# Usage: ./cow_highschool.sh <n>
# Prononce les carrés des entiers jusqu'à n.

if [ -z "$1" ] || ! [[ "$1" =~ ^[0-9]+$ ]]; then
  echo "Usage: $0 <nombre_entier>"
  exit 1
fi

n=$1
for ((i=1; i<=n; i++)); do
  square=$((i * i))
  clear
  cowsay "$square"
  sleep 1
done