#include <stdio.h>

#include "../include/expression.h"


/*
 * ============================================================
 * FONCTION DE TEST
 * ============================================================
 *
 * Affiche une expression, tente de la calculer et affiche
 * le résultat obtenu.
 */
static void tester(const char *expression)
{
    double resultat;

    printf("Expression : %s\n", expression);

    if (evaluer_expression(expression, &resultat))
    {
        printf("Resultat   : %.2f\n", resultat);
    }
    else
    {
        printf("ERREUR     : expression invalide\n");
    }

    printf("--------------------------------------------\n");
}


int main(void)
{
    printf("============================================\n");
    printf(" TEST MODULE EVALUATION DES EXPRESSIONS\n");
    printf("============================================\n");


    /*
     * ========================================================
     * ADDITION
     * ========================================================
     */

    printf("\n===== ADDITION =====\n\n");

    tester("2 + 3");
    tester("10 + 5");
    tester("-5 + 10");
    tester("2.5 + 3.5");


    /*
     * ========================================================
     * SOUSTRACTION
     * ========================================================
     */

    printf("\n===== SOUSTRACTION =====\n\n");

    tester("5 - 2");
    tester("10 - 15");
    tester("-5 - 3");
    tester("10.5 - 2.5");


    /*
     * ========================================================
     * MULTIPLICATION
     * ========================================================
     */

    printf("\n===== MULTIPLICATION =====\n\n");

    tester("2 * 3");
    tester("2 * 3 * 4");
    tester("-5 * 4");
    tester("5 * -4");
    tester("-5 * -4");
    tester("2.5 * 4");


    /*
     * ========================================================
     * DIVISION
     * ========================================================
     */

    printf("\n===== DIVISION =====\n\n");

    tester("20 / 4");
    tester("-20 / 4");
    tester("20 / -4");
    tester("-20 / -4");
    tester("5 / 2");
    tester("10.5 / 2");


    /*
     * ========================================================
     * PRIORITES DES OPERATIONS
     * ========================================================
     *
     * La multiplication et la division doivent être
     * effectuées avant l'addition et la soustraction.
     */

    printf("\n===== PRIORITES =====\n\n");

    tester("2 + 3 * 4");
    tester("10 - 2 * 3");
    tester("20 / 4 + 3");
    tester("2 * 3 + 4");
    tester("20 - 5 / 5");
    tester("10 + 2 * 3 - 4");


    /*
     * ========================================================
     * OPERATIONS DE MEME PRIORITE
     * ========================================================
     *
     * Les opérations sont effectuées de gauche à droite.
     */

    printf("\n===== MEME PRIORITE =====\n\n");

    tester("2 * 3 / 2");
    tester("20 / 2 / 5");
    tester("20 / 5 * 2");
    tester("10 + 5 - 3");
    tester("10 - 5 + 3");


    /*
     * ========================================================
     * PARENTHESES
     * ========================================================
     *
     * Les parenthèses permettent de modifier la priorité
     * normale des opérations.
     */

    printf("\n===== PARENTHESES =====\n\n");

    tester("(2 + 3) * 4");
    tester("2 * (3 + 4)");
    tester("(10 - 2) * 3");
    tester("20 / (2 + 3)");
    tester("(20 / 2) + 5");
    tester("2 + (3 * 4)");
    tester("((2 + 3) * 4)");


    /*
     * ========================================================
     * PARENTHÈSES IMBRIQUEES
     * ========================================================
     */

    printf("\n===== PARENTHESES IMBRIQUEES =====\n\n");

    tester("((2 + 3))");
    tester("((2 + 3) * 4)");
    tester("2 * ((3 + 4))");
    tester("(2 * (3 + 4))");
    tester("((2 + 3) * (4 + 5))");


    /*
     * ========================================================
     * SIGNES
     * ========================================================
     */

    printf("\n===== SIGNES =====\n\n");

    tester("-5");
    tester("+5");
    tester("-5 * 4");
    tester("5 * -4");
    tester("-(2 + 3)");
    tester("+(2 + 3)");
    tester("-(-2 * 3)");
    tester("-(2 * -3)");


    /*
     * ========================================================
     * NOMBRES DECIMAUX
     * ========================================================
     */

    printf("\n===== NOMBRES DECIMAUX =====\n\n");

    tester("2.5 + 3.5");
    tester("10.5 - 2.5");
    tester("2.5 * 4");
    tester("20.5 / 2.5");
    tester("2.5 + 3.5 * 2");
    tester("(2.5 + 3.5) * 2");


    /*
     * ========================================================
     * ESPACES
     * ========================================================
     *
     * Les espaces ne doivent pas modifier le résultat.
     */

    printf("\n===== ESPACES =====\n\n");

    tester("2+3");
    tester("2 + 3");
    tester(" 2 + 3 ");
    tester("2 * ( 3 + 4 )");
    tester("( 2 + 3 ) * 4");
    tester("10 - 2 * 3");


    /*
     * ========================================================
     * CAS D'ERREUR
     * ========================================================
     */

    printf("\n===== CAS D'ERREUR =====\n\n");

    /*
     * Division par zéro.
     */
    tester("2 / 0");

    /*
     * Parenthèse fermante manquante.
     */
    tester("(2 + 3");

    /*
     * Parenthèse fermante en trop.
     */
    tester("2 + 3)");

    /*
     * Parenthèses vides.
     */
    tester("2 * ()");

    /*
     * Opérateur sans opérande.
     */
    tester("2 +");

    /*
     * Deux opérateurs consécutifs.
     */
    tester("2 * / 3");

    /*
     * Deux nombres sans opérateur.
     */
    tester("2 3");

    /*
     * Expression vide.
     */
    tester("");

    /*
     * Parenthèses vides.
     */
    tester("()");

    /*
     * Opération incomplète.
     */
    tester("(2 + 3) *");


    printf("\n============================================\n");
    printf(" FIN DES TESTS\n");
    printf("============================================\n");

    return 0;
}