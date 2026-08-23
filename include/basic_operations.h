//implementer le prototype de chaque fonction
#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

/*
 * Additionne deux nombres.
 */
double additionner(double a, double b);

/*
 * Soustrait le deuxième nombre du premier.
 */
double soustraire(double a, double b);

/*
 * Multiplie deux nombres.
 */
double multiplier(double a, double b);

/*
 * Divise a par b.
 *
 * Retourne 1 si la division est réussie.
 * Retourne 0 si b est égal à zéro.
 *
 * Le résultat est stocké dans resultat.
 */
int diviser(double a, double b, double *resultat);

#endif