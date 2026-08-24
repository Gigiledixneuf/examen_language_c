# CLI scientific calculator 
Ce projet porte sur la réalisation d'une calcultrice scientifique en ligne de commande écrit en langage c dans le cadre de l'examen du cours de langage C  
Cette calculatrice scientifique offre aux utilisateur la possibilité d'effectuer les calculs scientifiques allant des opérations mathematiques de base aux fonctions avancées.


 ## Guide d'installation
 - installation du  le compilateur gcc
 - cloner le repo
 ### compiler le programme

 #### sans make:

 ```
  gcc -Wall -I ./include ./src/main.c  ./src/interface.c ./src/basic_operations.c  -o ./bin/main

#### avec make

```
## Structures des dossiers
 ## Usages
 ## Test des modules
 Les projet est subdivisé en trois modules.
 - modules interface : ce module contient ctout le code relatif à l'interface utilisateurs.
 - le module des opérations basiques : ce modules comprend toute la logique metier relatif aux opérations arithmetique de base.
 - le module des opérations scientifiques avancées : ce module contient toute la logiques metiers relatif aux operations scientifique avancées.
 ```
  gcc -Wall -I ./include ./tests/main.test.c ./src/interface.c ./src/basic_operations.c -o ./bin/main_test
  ```
 ## License
## Auteurs

Project Title  a été cree par **[Nom des membres du groupe](https://github.com/username)**.
