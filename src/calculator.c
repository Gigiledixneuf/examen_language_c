#include "../include/calculator.h"

#include "../include/interface.h"

#include <stdio.h>


void baseFlow(void)
{
    int choice;

    printf("\n");
    printf("========== CALCULATRICE ==========\n");
    printf("1. Effectuer un calcul\n");
    printf("2. Afficher l'historique\n");
    printf("0. Quitter\n");
    printf("==================================\n");

    printf("Votre choix : ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            CalculatorContext context = {
                .result = 0.0,
                .firstValue = 0.0,
                .secondValue = 0.0,
                .isInitialExecution = true,
                .currentOperator = 0
            };

            calculationFlow(&context);
            break;
        }

        case 2:
            /*
             * L'historique sera branché ici.
             */
            printf("\nHistorique :\n");
            printf("Fonctionnalité en cours d'implémentation.\n");
            break;

        case 0:
            printf("Au revoir.\n");
            return;

        default:
            printf("Choix invalide.\n");
            break;
    }
}

void calculationFlow(
    CalculatorContext *context
)
{
    int operatorChoice;

    operatorChoice = getOperatorChoice();

    if (operatorChoice == 0)
    {
        return;
    }

    context->currentOperator = operatorChoice;

    /*
     * Pour l'instant, on traite seulement
     * la distinction unaire / non-unaire.
     */
    Operator operator =
        defineOperator(operatorChoice);

    if (operator.isUnary)
    {
        printf("\nOperation unaire selectionnee.\n");
    }
    else
    {
        printf("\nOperation non unaire selectionnee.\n");
    }
}