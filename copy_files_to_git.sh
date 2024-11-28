#!/bin/bash

# Vérification des arguments
if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <prefixe_source> <prefixe_destination> <fichier_liste_suffixes>"
  exit 1
fi

# Récupération des arguments
prefixe_source=$1
prefixe_destination=$2
fichier_liste_suffixes=$3

# Vérification que le fichier liste existe
if [ ! -f "$fichier_liste_suffixes" ]; then
  echo "Fichier liste des suffixes introuvable : $fichier_liste_suffixes"
  exit 1
fi

# Création du préfixe de destination si nécessaire
#mkdir -p "$prefixe_destination"

# Lecture du fichier de suffixes et copie des fichiers
while IFS= read -r suffixe || [ -n "$suffixe" ]; do
  # Ignorer les lignes vides
  [ -z "$suffixe" ] && continue

  # Chemins complets
  source_path="${prefixe_source}${suffixe}"
  destination_path="${prefixe_destination}${suffixe}"

  # Création du dossier de destination si nécessaire
  #mkdir -p "$(dirname "$destination_path")"

  # Copie du fichier
  if [ -f "$source_path" ]; then
    cp "$source_path" "$destination_path"
    echo "Copié : $source_path -> $destination_path"
  else
    echo "Fichier introuvable : $source_path"
  fi
done < "$fichier_liste_suffixes"

echo "Traitement terminé."
