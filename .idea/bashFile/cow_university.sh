#!/usr/bin/env bash
# cow_university.sh
# Usage: ./cow_university.sh <n>
# Affiche les nombres premiers < n avec cowsay

# Vérification que l'argument est bien fourni et est un entier
if [ -z "$1" ] || ! [[ "$1" =~ ^[0-9]+$ ]]; then
  echo "Usage: $0 <nombre_entier>"
  exit 1
fi

n=$1

# Fonction qui teste si un nombre donné est premier
is_prime() {
  local i=$1  # Prend directement i en paramètre
  if (( i <= 1 )); then
    return 1
  fi
  for ((j=2; j*j<=i; j++)); do
    if (( i % j == 0 )); then
      return 1
    fi
  done
  return 0
}

# Boucle sur les entiers de 2 à n-1
for ((i=2; i<n; i++)); do
  if is_prime "$i"; then
    clear
    cowsay "$i"
    sleep 1
  fi
done
