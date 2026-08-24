#include "../include/basic_operations.h"
#include <stddef.h>
//guerchom  & benel & isaac: module: basic operations
//implementer les fonctions ici

//addition: prend en parametre deux nombre et les additionne

//soustraction: prend en parametre deux nombre et les soustrait

//multipication: prend en parametre deux nombre et les multiplie
/*
 * ------------------------------------------------------------
 * MULTIPLICATION
 * ------------------------------------------------------------
 *
 * Multiplie deux nombres a et b.
 *
 * Exemple :
 *
 *     a = 5
 *     b = 4
 *
 *     résultat = 20
 *
 * La fonction retourne directement le résultat du calcul.
 */
double multiplier(double a, double b)
{
    return a * b;
}


/*
 * ------------------------------------------------------------
 * DIVISION
 * ------------------------------------------------------------
 *
 * Divise le nombre a par le nombre b.
 *
 * Le résultat est placé dans la variable pointée par
 * le paramètre resultat.
 *
 * La fonction vérifie deux conditions :
 *
 * 1. Le diviseur b ne doit pas être égal à zéro.
 * 2. L'adresse resultat doit être valide.
 *
 * Retour :
 *
 *     1 -> division réussie
 *     0 -> erreur
 *
 * Exemple :
 *
 *     double resultat;
 *
 *     if (diviser(20, 4, &resultat))
 *     {
 *         printf("%.2f", resultat);
 *     }
 *
 * Résultat :
 *
 *     5.00
 */
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