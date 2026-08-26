# CLI Scientific Calculator

Calculatrice scientifique en ligne de commande écrite en C — projet réalisé dans le cadre de l'examen de Langage C, L1 Informatique, UPN.

## Fonctionnalités

- Opérations de base : addition, soustraction, multiplication, division
- Fonctions scientifiques : sin, cos, tan, exp, log10, ln, log base quelconque, puissance, factorielle, racine carrée, racine n-ième
- Conversion entre bases numériques (binaire, octal, décimal, hexadécimal)
- Historique des calculs (enregistré dans `data/history.txt`)
- Enchaînement de calculs (même opérateur ou opérateur différent)

## Installation (Windows)

### 1. Prérequis
- **Git** — pour récupérer le projet
- **GCC** — pour compiler le programme
- **Make** — pour automatiser la compilation

Nous recommandons **MSYS2 / MinGW-w64** pour installer GCC et Make.

### 2. Installer GCC et Make avec MSYS2

Télécharger et installer MSYS2 depuis [msys2.org](https://www.msys2.org/).

Ouvrir le terminal **MSYS2 UCRT64** puis installer les outils :
```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

Vérifier l'installation :
```bash
gcc --version
make --version
```

### 3. Ajouter GCC au PATH Windows

Pour utiliser GCC/Make depuis l'invite de commandes (cmd) :
1. `Win + R` → taper `sysdm.cpl` → Entrée
2. Onglet **Paramètres système avancés** → **Variables d'environnement**
3. Sélectionner la variable **Path** → **Modifier** → **Nouveau**
4. Ajouter : `C:\msys64\ucrt64\bin`
5. Valider toutes les fenêtres, puis fermer/rouvrir les invites cmd déjà ouvertes

### 4. Installer Git

Télécharger depuis [git-scm.com/downloads](https://git-scm.com/downloads), puis vérifier :
```bash
git --version
```

### 5. Récupérer le projet

```bash
git clone https://github.com/Gigiledixneuf/examen_language_c.git
```

Un dossier `examen_language_c` sera créé.

### 6. Ouvrir le projet dans l'invite de commandes

1. Ouvrir l'**Explorateur de fichiers** et aller dans `examen_language_c`
2. Cliquer dans la barre d'adresse en haut
3. Taper `cmd` puis Entrée

Une fenêtre s'ouvre directement dans le dossier du projet.

## Compilation et exécution

```bash
make          # compiler le projet
make run      # exécuter l'application
make test     # lancer les tests unitaires (dossier tests/)
make clean    # supprimer les fichiers générés
```

## Structure du projet

```
examen_language_c/
├── include/       # fichiers d'en-tête (.h)
├── src/           # implémentation du programme
├── tests/         # tests unitaires
├── data/          # historique des calculs (history.txt)
├── bin/           # exécutables générés
└── Makefile
```

## Utilisation

Menu principal :
```
1. Effectuer un calcul
2. Afficher l'historique
0. Quitter
```

**Raccourcis pendant un calcul :**
| Touche | Action |
|---|---|
| ENTER | Continuer avec le même opérateur (paramètres mémorisés) |
| ESPACE | Utiliser le résultat précédent avec un nouvel opérateur |
| BACKSPACE | Revenir au menu principal |
| ESC | Quitter le programme |

**Exemples :**
- `2 + 3 = 5` → ENTER → `5 + 4 = 9`
- `2 ^ 3 = 8` → ENTER → `8 ^ 3 = 512` (exposant conservé)
- `sin(30°) = 0.5`
- `log₂(8) = 3` → ENTER → base conservée, résultat précédent réutilisé

Pour les fonctions trigonométriques, l'unité de l'angle (degrés/radians) est demandée puis conservée en cas d'enchaînement.

## Dépôt GitHub

https://github.com/Gigiledixneuf/examen_language_c

## Auteurs

| Nom | GitHub |
|---|---|
| Amos Kalunga | [à compléter] |
| Élysée | [à compléter] |
| Manassé | [à compléter] |
| Daniella | [à compléter] |
| Jonathan | [à compléter] |
| Juliette | [à compléter] |
| Guershom | [à compléter] |
| Sebastien | [à compléter] |
| Benel | [à compléter] |
| Geraldine | [à compléter] |
| Isaac | [à compléter] |