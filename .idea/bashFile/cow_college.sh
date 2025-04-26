#!/usr/bin/env bash
# cow_college.sh
# Usage: ./cow_college.sh <n>
# Prononce les termes de Fibonacci < n.

if [ -z "$1" ] || ! [[ "$1" =~ ^[0-9]+$ ]]; then
  echo "Usage: $0 <nombre_entier>"
  exit 1
fi

n=$1
a=1
b=2

while [ "$a" -lt "$n" ]; do
  clear
  cowsay "$a"
  sleep 1
  fn=$((a + b))
  a=$b   # <-- ici sans ( )
  b=$fn  # <-- ici sans ( )
done
