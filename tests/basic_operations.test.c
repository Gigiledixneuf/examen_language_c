#include <stdio.h>
#include "../include/basic_operations.h"

int main(void)
{
    double resultat;

    printf("============================================\n");
    printf(" TEST MODULE MULTIPLICATION / DIVISION\n");
    printf("============================================\n\n");

    /* ============================= */
    /* TESTS MULTIPLICATION           */
    /* ============================= */

    printf("===== TESTS MULTIPLICATION =====\n\n");

    printf("5 * 4 = %.2f\n", multiplier(5, 4));

    printf("-5 * 4 = %.2f\n", multiplier(-5, 4));

    printf("5 * -4 = %.2f\n", multiplier(5, -4));

    printf("-5 * -4 = %.2f\n", multiplier(-5, -4));

    printf("2.5 * 4 = %.2f\n", multiplier(2.5, 4));

    printf("0 * 100 = %.2f\n", multiplier(0, 100));


    /* ============================= */
    /* TESTS DIVISION                */
    /* ============================= */

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


    /* ============================= */
    /* DIVISION PAR ZERO             */
    /* ============================= */

    printf("\n===== CAS D'ERREUR =====\n\n");

    if (diviser(20, 0, &resultat))
    {
        printf("20 / 0 = %.2f\n", resultat);
    }
    else
    {
        printf("20 / 0 -> ERREUR : division par zero impossible.\n");
    }

    return 0;
}