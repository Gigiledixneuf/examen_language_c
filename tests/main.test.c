#include <stdio.h>
#include "../include/basic_operations.h"

int main(void)
{
    double resultat;

    printf("============================================\n");
    printf(" TEST MODULE OPERATIONS DE BASE\n");
    printf("============================================\n\n");


    /*
     * ========================================================
     * ADDITION
     * ========================================================
     *
     * Vérifie le fonctionnement de l'addition
     * avec des nombres positifs, négatifs et décimaux.
     */

    printf("===== TESTS ADDITION =====\n\n");

    printf("5 + 4 = %.2f\n", additionner(5, 4));

    printf("-5 + 4 = %.2f\n", additionner(-5, 4));

    printf("5 + -4 = %.2f\n", additionner(5, -4));

    printf("-5 + -4 = %.2f\n", additionner(-5, -4));

    printf("2.5 + 4 = %.2f\n", additionner(2.5, 4));

    printf("0 + 100 = %.2f\n", additionner(0, 100));


    /*
     * ========================================================
     * SOUSTRACTION
     * ========================================================
     *
     * Vérifie le fonctionnement de la soustraction
     * avec différents types de valeurs.
     */

    printf("\n===== TESTS SOUSTRACTION =====\n\n");

    printf("5 - 4 = %.2f\n", soustraire(5, 4));

    printf("-5 - 4 = %.2f\n", soustraire(-5, 4));

    printf("5 - -4 = %.2f\n", soustraire(5, -4));

    printf("-5 - -4 = %.2f\n", soustraire(-5, -4));

    printf("2.5 - 4 = %.2f\n", soustraire(2.5, 4));

    printf("100 - 100 = %.2f\n", soustraire(100, 100));


    /*
     * ========================================================
     * MULTIPLICATION
     * ========================================================
     */

    printf("\n===== TESTS MULTIPLICATION =====\n\n");

    printf("5 * 4 = %.2f\n", multiplier(5, 4));

    printf("-5 * 4 = %.2f\n", multiplier(-5, 4));

    printf("5 * -4 = %.2f\n", multiplier(5, -4));

    printf("-5 * -4 = %.2f\n", multiplier(-5, -4));

    printf("2.5 * 4 = %.2f\n", multiplier(2.5, 4));

    printf("0 * 100 = %.2f\n", multiplier(0, 100));


    /*
     * ========================================================
     * DIVISION
     * ========================================================
     *
     * La fonction diviser() retourne :
     *
     *     1 -> division réussie
     *     0 -> division impossible
     */

    printf("\n===== TESTS DIVISION =====\n\n");

    if (diviser(20, 4, &resultat))
    {
        printf("20 / 4 = %.2f\n", resultat);
    }

    if (diviser(-20, 4, &resultat))
    {
        printf("-20 / 4 = %.2f\n", resultat);
    }

    if (diviser(20, -4, &resultat))
    {
        printf("20 / -4 = %.2f\n", resultat);
    }

    if (diviser(-20, -4, &resultat))
    {
        printf("-20 / -4 = %.2f\n", resultat);
    }

    if (diviser(5, 2, &resultat))
    {
        printf("5 / 2 = %.2f\n", resultat);
    }

    if (diviser(0, 5, &resultat))
    {
        printf("0 / 5 = %.2f\n", resultat);
    }


    /*
     * ========================================================
     * CAS D'ERREUR : DIVISION PAR ZERO
     * ========================================================
     */

    printf("\n===== CAS D'ERREUR =====\n\n");

    if (diviser(20, 0, &resultat))
    {
        printf("20 / 0 = %.2f\n", resultat);
    }
    else
    {
        printf("20 / 0 -> ERREUR : division par zero impossible.\n");
    }


    /*
     * ========================================================
     * FIN DES TESTS
     * ========================================================
     */

    printf("\n============================================\n");
    printf(" FIN DES TESTS OPERATIONS DE BASE\n");
    printf("============================================\n");

    return 0;
}