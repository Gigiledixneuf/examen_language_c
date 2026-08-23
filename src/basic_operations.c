#include "../include/basic_operations.h"
//guerchom  & benel & isaac: module: basic operations
//implementer les fonctions ici

//addition: prend en parametre deux nombre et les additionne

//soustraction: prend en parametre deux nombre et les soustrait

//multipication: prend en parametre deux nombre et les multiplie
double multiplier(double a, double b){
    return a*b;
}

// division : prend en parametre deux nombre et les divise en faisant attention à ce que le deuxieme nombre sois different de zero, si c'est le cas lever une exception
/*
 * Divise deux nombres.
 *
 * Retourne 1 si la division est possible.
 * Retourne 0 si le diviseur est nul.
 *
 * Le résultat est stocké dans resultat.
 */
int diviser(double a, double b, double *resultat)
{
    if (b == 0)
    {
        return 0;
    }

    *resultat = a / b;

    return 1;
}

//test des chaque fonction individuellement en ligne de commande

//total: 4 fonctions