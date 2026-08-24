//implementer le prototype de chaque fonction
#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

/*
 * ============================================================
 * MODULE : OPERATIONS DE BASE
 * ============================================================
 *
 * Ce module contient les opérations arithmétiques de base
 * utilisées par la calculatrice scientifique.
 *
 * Répartition du travail :
 *
 * - Addition       : Benel / Isaac
 * - Soustraction   : Benel / Isaac
 * - Multiplication : Guerchom
 * - Division       : Guerchom
 *
 * Les fonctions d'addition et de soustraction sont déclarées
 * ici afin de permettre l'intégration future de tous les membres
 * du groupe dans le même module.
 */


/*
 * ------------------------------------------------------------
 * ADDITION
 * ------------------------------------------------------------
 *
 * Additionne deux nombres.
 *
 * double addition(double a, double b);

Cette fonction est réservée à l'implémentation de Benel
 * et Isaac.
 */
double additionner(double a, double b);


/*
 * ------------------------------------------------------------
 * SOUSTRACTION
 * ------------------------------------------------------------
 *
 * Soustrait b de a.
 *
 * Cette fonction est réservée à l'implémentation de Benel
 * et Isaac.
 */
double soustraire(double a, double b);


/*
 * ------------------------------------------------------------
 * MULTIPLICATION
 * ------------------------------------------------------------
 *
 * Multiplie a par b.
 *
 * Exemple :
 *
 *     multiplier(5, 4)
 *
 * retourne :
 *
 *     20
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