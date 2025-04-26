#!/usr/bin/env bash
# crazy_cow.sh
# La vache prononce 10 valeurs hexadécimales aléatoires.

for i in {1..10}; do
  hex=$(printf "%x" $((RANDOM % 256)))
  clear
  cowsay "$hex"
  sleep 1
done