#include "calculator.h"

#include "../include/interface.h"
#include "../include/basic_operations.h"
#include "../include/advanced_operations.h"
#include "../include/base_conversion.h"
#include "../include/history.h"

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_SPACE 32
#define KEY_BACKSPACE 8


static void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}


/* =========================================================
 * UTILITAIRE : demander une valeur
 * ========================================================= */

static double askValue(void)
{
    double value;

    printf("Veuillez entrer la valeur : ");
    scanf("%lf", &value);

    return value;
}


/* =========================================================
 * OPERATIONS DE BASE
 * ========================================================= */

static bool executeBasicOperation(
    int operator,
    CalculatorContext *context,
    char *expression
)
{
    double value;
    double result;

    if (context->isInitialExecution)
    {
        double first;
        double second;

        printf("Veuillez entrer le premier nombre : ");
        scanf("%lf", &first);

        printf("Veuillez entrer le deuxieme nombre : ");
        scanf("%lf", &second);

        bool success = false;

        switch (operator)
        {
            case 1:
                success = add(first, second, &result);

                if (success)
                    sprintf(
                        expression,
                        "%.10g + %.10g",
                        first,
                        second
                    );
                break;

            case 2:
                success = subtract(first, second, &result);

                if (success)
                    sprintf(
                        expression,
                        "%.10g - %.10g",
                        first,
                        second
                    );
                break;

            case 3:
                success = multiply(first, second, &result);

                if (success)
                    sprintf(
                        expression,
                        "%.10g * %.10g",
                        first,
                        second
                    );
                break;

            case 4:
                success = divide(first, second, &result);

                if (success)
                    sprintf(
                        expression,
                        "%.10g / %.10g",
                        first,
                        second
                    );

                if (!success)
                {
                    printf("Erreur : division par zero.\n");
                }

                break;

            default:
                return false;
        }

        if (!success)
        {
            return false;
        }

        context->result = result;

        return true;
    }


    /* -----------------------------------------------------
     * ENCHAINEMENT AVEC LE MEME OPERATEUR
     * ----------------------------------------------------- */

    value = askValue();

    bool success = false;

    switch (operator)
    {
        case 1:
            success = add(
                context->result,
                value,
                &result
            );

            if (success)
                sprintf(
                    expression,
                    "%.10g + %.10g",
                    context->result,
                    value
                );

            break;

        case 2:
            success = subtract(
                context->result,
                value,
                &result
            );

            if (success)
                sprintf(
                    expression,
                    "%.10g - %.10g",
                    context->result,
                    value
                );

            break;

        case 3:
            success = multiply(
                context->result,
                value,
                &result
            );

            if (success)
                sprintf(
                    expression,
                    "%.10g * %.10g",
                    context->result,
                    value
                );

            break;

        case 4:
            success = divide(
                context->result,
                value,
                &result
            );

            if (!success)
            {
                printf("Erreur : division par zero.\n");
                return false;
            }

            sprintf(
                expression,
                "%.10g / %.10g",
                context->result,
                value
            );

            break;

        default:
            return false;
    }

    context->result = result;

    return true;
}


/* =========================================================
 * OPERATIONS UNAIRES
 * ========================================================= */

static bool executeUnaryOperation(
    int operator,
    CalculatorContext *context,
    char *expression
)
{
    double value;
    double result;

    if(context->isInitialExecution){
        value = askValue();
    }else{
        value=context->result;
    }

    bool success = false;

    switch (operator)
    {
        case 5:
        case 6:
        case 7:
        {
            int unit;

            printf("\nUnite de l'angle :\n");
            printf("1. Degres\n");
            printf("2. Radians\n");
            printf("Choix : ");

            scanf("%d", &unit);

            AngleUnit angleUnit;

            if (unit == 1)
            {
                angleUnit = ANGLE_DEGREES;
            }
            else if (unit == 2)
            {
                angleUnit = ANGLE_RADIANS;
            }
            else
            {
                printf("Unite invalide.\n");
                return false;
            }

            if (operator == 5)
            {
                success = calculate_sin(
                    value,
                    angleUnit,
                    &result
                );

                sprintf(
                    expression,
                    "sin(%.10g)",
                    value
                );
            }
            else if (operator == 6)
            {
                success = calculate_cos(
                    value,
                    angleUnit,
                    &result
                );

                sprintf(
                    expression,
                    "cos(%.10g)",
                    value
                );
            }
            else
            {
                success = calculate_tan(
                    value,
                    angleUnit,
                    &result
                );

                sprintf(
                    expression,
                    "tan(%.10g)",
                    value
                );
            }

            break;
        }

        case 8:

            success = calculate_exp(
                value,
                &result
            );

            sprintf(
                expression,
                "exp(%.10g)",
                value
            );

            break;

        case 9:

            success = calculate_log10(
                value,
                &result
            );

            sprintf(
                expression,
                "log10(%.10g)",
                value
            );

            break;

        case 10:

            success = calculate_ln(
                value,
                &result
            );

            sprintf(
                expression,
                "ln(%.10g)",
                value
            );

            break;

        case 13:

            success = calculate_factorial(
                value,
                &result
            );

            sprintf(
                expression,
                "%.10g!",
                value
            );

            break;

        case 14:

            success = calculate_sqrt(
                value,
                &result
            );

            sprintf(
                expression,
                "sqrt(%.10g)",
                value
            );

            break;

        default:
            return false;
    }

    if (!success)
    {
        printf("Erreur : operation impossible.\n");
        return false;
    }

    context->result = result;

    return true;
}


/* =========================================================
 * PUISSANCE
 * ========================================================= */

static bool executePower(
    CalculatorContext *context,
    char *expression
)
{
    double base;
    double exponent;
    double result;
    if(context->isInitialExecution){
        printf("Entrez la base : ");
    scanf("%lf", &base);
    }else{
        base=context->result;
    }
    

    printf("Entrez l'exposant : ");
    scanf("%lf", &exponent);

    if (!calculate_power(
        base,
        exponent,
        &result
    ))
    {
        return false;
    }

    context->result = result;

    sprintf(
        expression,
        "%.10g ^ %.10g",
        base,
        exponent
    );

    return true;
}


/* =========================================================
 * LOGARITHME A BASE QUELCONQUE
 * ========================================================= */

static bool executeLogBase(
    CalculatorContext *context,
    char *expression
)
{
    double value;
    double base;
    double result;


    printf("Entrez la valeur : ");
    scanf("%lf", &value);

    if(context->isInitialExecution){
        printf("Entrez la valeur : ");
    scanf("%lf", &value);
    }else{
        value=context->result;
    }
    printf("Entrez la base : ");
    scanf("%lf", &base);

    if (!calculate_log_base(
        value,
        base,
        &result
    ))
    {
        return false;
    }

    context->result = result;

    sprintf(
        expression,
        "log_%.10g(%.10g)",
        base,
        value
    );

    return true;
}


/* =========================================================
 * RACINE N-IEME
 * ========================================================= */

static bool executeNthRoot(
    CalculatorContext *context,
    char *expression
)
{
    double value;
    double n;
    double result;

    printf("Entrez la valeur : ");
    scanf("%lf", &value);

    printf("Entrez l'indice n : ");
    scanf("%lf", &n);

    if (!calculate_nth_root(
        value,
        n,
        &result
    ))
    {
        return false;
    }

    context->result = result;

    sprintf(
        expression,
        "racine_%g(%.10g)",
        n,
        value
    );

    return true;
}


/* =========================================================
 * CHANGEMENT DE BASE
 * ========================================================= */

static bool executeBaseConversion(
    CalculatorContext *context
)
{
    char value[128];
    char result[128];

    int sourceBase;
    int targetBase;

    printf("Entrez la valeur : ");
    scanf("%127s", value);

    printf("Base initiale (2, 8, 10, 16) : ");
    scanf("%d", &sourceBase);

    printf("Base cible (2, 8, 10, 16) : ");
    scanf("%d", &targetBase);

    if (!convert_base(
        value,
        sourceBase,
        targetBase,
        result,
        sizeof(result)
    ))
    {
        printf("Erreur : conversion impossible.\n");
        return false;
    }

    printf(
        "\nResultat : %s\n",
        result
    );

    /*
     * Le changement de base ne modifie pas
     * le resultat numerique du contexte.
     */

    return true;
}


/* =========================================================
 * ECOUTE APRES RESULTAT
 * ========================================================= */

static int listenAfterResult(void)
{
    printf("\n");
    printf("ENTER     : enchainer avec le meme operateur\n");
    printf("ESPACE    : enchainer avec un operateur different\n");
    printf("BACKSPACE : revenir au flux de base\n");
    printf("ESC       : quitter\n");

    return getch();
}


/* =========================================================
 * FLUX 3
 * ========================================================= */

void sameOperatorFlow(
    CalculatorContext *context
)
{
    context->isInitialExecution = false;

    char expression[256];

    memset(expression, 0, sizeof(expression));

    Operator operator =
        defineOperator(context->currentOperator);

    bool success = false;

    if (operator.isBasic)
    {
        success = executeBasicOperation(
            context->currentOperator,
            context,
            expression
        );
    }
    else
    {
        /*
         * Le flux 3 concerne l'enchaînement
         * avec le même opérateur.
         *
         * Pour les opérations nécessitant plusieurs
         * paramètres, on repasse par le flux de calculs.
         */
        calculationFlow(context);
        return;
    }

    if (!success)
    {
        return;
    }

    printf(
        "\nResultat = %.10g\n",
        context->result
    );

    saveHistory(
        expression,
        context->result
    );

    int key = listenAfterResult();

    if (key == KEY_ENTER)
    {
        sameOperatorFlow(context);
    }
    else if (key == KEY_SPACE)
    {
        differentOperatorFlow(context);
    }
    else if (key == KEY_BACKSPACE)
    {
        baseFlow();
    }
}


/* =========================================================
 * FLUX 4
 * ========================================================= */

void differentOperatorFlow(
    CalculatorContext *context
)
{
    context->isInitialExecution = false;

    calculationFlow(context);
}


/* =========================================================
 * FLUX DE CALCULS
 * ========================================================= */

void calculationFlow(
    CalculatorContext *context
)
{
    char expression[256];

    memset(expression, 0, sizeof(expression));

    Operator operator;

    int choice;

    choice = getOperatorChoice();

    if (choice == 0)
    {
        return;
    }

    operator = defineOperator(choice);

    context->currentOperator = choice;


    /* -----------------------------------------------------
     * OPERATION UNAIRE
     * ----------------------------------------------------- */

    if (operator.isUnary)
    {
        if (!executeUnaryOperation(
            choice,
            context,
            expression
        ))
        {
            return;
        }
    }


    /* -----------------------------------------------------
     * OPERATION DE BASE
     * ----------------------------------------------------- */

    else if (operator.isBasic)
    {
        if (!executeBasicOperation(
            choice,
            context,
            expression
        ))
        {
            return;
        }
    }


    /* -----------------------------------------------------
     * CHOIX MULTIPLE
     * ----------------------------------------------------- */

    else
    {
        switch (choice)
        {
            case 11:

                if (!executeLogBase(
                    context,
                    expression
                ))
                {
                    return;
                }

                break;


            case 12:

                if (!executePower(
                    context,
                    expression
                ))
                {
                    return;
                }

                break;


            case 15:

                if (!executeNthRoot(
                    context,
                    expression
                ))
                {
                    return;
                }

                break;


            case 16:

                executeBaseConversion(context);

                /*
                 * Le changement de base possède
                 * son propre cycle.
                 */
                return;


            default:

                /*
                 * Retour au flux de calculs
                 */
                calculationFlow(context);

                return;
        }
    }


    /* -----------------------------------------------------
     * RESULTAT
     * ----------------------------------------------------- */

    printf(
        "\nResultat = %.10g\n",
        context->result
    );


    /*
     * L'historique est enregistré ici,
     * après un calcul réussi.
     */
    saveHistory(
        expression,
        context->result
    );


    /* -----------------------------------------------------
     * ECOUTE CLAVIER
     * ----------------------------------------------------- */

    int key = listenAfterResult();


    if (key == KEY_ENTER)
    {
        sameOperatorFlow(context);
    }
    else if (key == KEY_SPACE)
    {
        differentOperatorFlow(context);
    }
    else if (key == KEY_BACKSPACE)
    {
        baseFlow();
    }
    else if (key == KEY_ESC)
    {
        return;
    }
}


/* =========================================================
 * FLUX DE BASE
 * ========================================================= */

void baseFlow(void)
{
    int choice;

    while (true)
    {
        system("cls");

        printf("\n");
        printf("========== CALCULATRICE ==========\n");
        printf("1. Effectuer un calcul\n");
        printf("2. Afficher l'historique\n");
        printf("0. Quitter\n");
        printf("==================================\n");

        printf("Votre choix : ");

        scanf("%d", &choice);

        clearInputBuffer();

        switch (choice)
        {
            case 1:
            {
                CalculatorContext context;

                context.result = 0.0;
                context.isInitialExecution = true;
                context.currentOperator = 0;

                calculationFlow(&context);

                break;
            }

            case 2:

                displayHistory();

                break;

            case 0:

                return;

            default:

                printf("Choix invalide.\n");
                break;
        }
    }
}