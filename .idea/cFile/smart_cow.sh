#!/usr/bin/env bash
# smart_cow.sh
# Usage: ./smart_cow.sh "<op1><op><op2>"
# Exemple: ./smart_cow.sh "3+11"

expr="$1"

# Si l'expression est vide, afficher l'usage
if [ -z "$expr" ]; then
  echo "Usage: $0 \"<nombre1><+|-|*|/><nombre2>\""
  exit 1
fi

# Calculer le résultat avec bc
result=$(echo "scale=0; $expr" | bc 2>/dev/null)

# Vérifier si bc a échoué (par exemple une expression invalide)
if [ $? -ne 0 ] || [ -z "$result" ]; then
  echo "Erreur : expression invalide."
  echo "Usage: $0 \"<nombre1><+|-|*|/><nombre2>\""
  exit 1
fi

# Limiter les yeux à deux caractères (padding/troncation)
eyes=$(printf "%2s" "$result" | sed 's/ /_/g' | cut -c1-2)

clear
cowsay -e "$eyes" "$expr"
