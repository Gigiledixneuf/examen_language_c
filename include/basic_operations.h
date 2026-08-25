//implementer le prototype de chaque fonction
#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

/*
 * ============================================================
 * MODULE : OPERATIONS DE BASE
 * ============================================================
 *
 * Ce module contient les opérations arithmétiques de base utilisées par la calculatrice scientifique.
 */


/*
 * ------------------------------------------------------------
 * ADDITION
 * ------------------------------------------------------------
 *
 * Additionne deux nombres.
 *
 * double addition(double a, double b);
 */
double additionner(double a, double b);


/*
 * ------------------------------------------------------------
 * SOUSTRACTION
 * ------------------------------------------------------------
 *
 * Soustrait b de a.
 */
double soustraire(double a, double b);


/*
 * ------------------------------------------------------------
 * MULTIPLICATION
 * ------------------------------------------------------------
 *
 * Multiplie a par b.
 */
double multiplier(double a, double b);


/*
 * ------------------------------------------------------------
 * DIVISION
 * ------------------------------------------------------------
 *
 * Divise a par b.
 *
 * Paramètres :
 *
 *     a         : dividende
 *     b         : diviseur
 *     resultat  : adresse dans laquelle sera stocké le résultat
 *
 * Retour :
 *
 *     1 -> division réussie
 *     0 -> division impossible
 *
 * Une division par zéro est considérée comme une erreur.
 */
int diviser(double a, double b, double *resultat);

#endif