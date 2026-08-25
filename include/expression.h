#ifndef EXPRESSION_H
#define EXPRESSION_H

/*
 * ============================================================
 * MODULE : EVALUATION DES EXPRESSIONS
 * ============================================================
 *
 * Évalue une expression mathématique contenant :
 *
 * - des nombres entiers ou décimaux
 * - l'addition (+)
 * - la soustraction (-)
 * - la multiplication (*)
 * - la division (/)
 * - des parenthèses
 * - les signes + et - devant une valeur ou une expression
 *
 * Les priorités mathématiques sont respectées :
 *
 * 1. Parenthèses
 * 2. Multiplication et division
 * 3. Addition et soustraction
 *
 * Retour :
 *
 *     1 -> expression valide
 *     0 -> expression invalide
 *
 * Le résultat est stocké dans resultat.
 */
int evaluer_expression(const char *expression, double *resultat);

#endif