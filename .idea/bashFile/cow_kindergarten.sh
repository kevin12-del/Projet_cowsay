#!/usr/bin/env bash
# cow_kindergarten.sh
# Prononce les chiffres de 1 à 10, pause 1s, vache tire la langue.

for i in {1..10}; do
  clear
  cowsay "$i"
  sleep 1
done

# À la fin, la vache tire la langue (-T "U ")
cowsay -T "U " "Fin de l'exercice"