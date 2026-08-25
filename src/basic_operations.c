#include "../include/basic_operations.h"
#include <stddef.h>

//addition: prend en parametre deux nombre et les additionne
double additionner(double a, double b)
{
    return a + b;
}

//soustraction: prend en parametre deux nombre et les soustrait
double soustraire(double a, double b)
{
    return a - b;
}

//multipication: prend en parametre deux nombre et les multiplie
double multiplier(double a, double b)
{
    return a * b;
}


//la division: prend en parametre deux nombre et les divise
int diviser(double a, double b, double *resultat)
{
    /*
     * Une division par zéro est impossible.
     */
    if (b == 0)
    {
        return 0;
    }

    /*
     * Vérification de l'adresse de stockage du résultat.
     *
     * Cela évite d'écrire dans une adresse mémoire invalide.
     */
    if (resultat == NULL)
    {
        return 0;
    }

    /*
     * Effectue la division et stocke le résultat.
     */
    *resultat = a / b;

    return 1;
}
//test des chaque fonction individuellement en ligne de commande

//total: 4 fonctions