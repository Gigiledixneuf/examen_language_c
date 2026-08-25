#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdbool.h>

#define MAX_RESULT_LENGTH 128

typedef enum
{
    OP_ADD = 1,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,

    OP_SIN,
    OP_COS,
    OP_TAN,

    OP_EXP,
    OP_LOG10,
    OP_LN,
    OP_LOG_BASE,

    OP_POWER,
    OP_FACTORIAL,
    OP_SQRT,
    OP_NTH_ROOT,

    OP_BASE_CONVERSION

} OperatorType;


typedef struct
{
    OperatorType type;

    bool isBasic;
    bool isTrigo;
    bool isUnary;

} Operator;


/*
 * Etat conservé pendant l'exécution
 * d'un calcul.
 */
typedef struct
{
    double numericResult;

    char textualResult[MAX_RESULT_LENGTH];

    bool hasNumericResult;
    bool hasTextualResult;

    bool isInitialExecution;

    Operator currentOperator;

} CalculatorState;


/*
 * Flux principaux
 */

void executeBaseFlow(void);

void executeCalculationFlow(CalculatorState *state);

void executeSameOperatorFlow(CalculatorState *state);

void executeDifferentOperatorFlow(CalculatorState *state);

void executeBaseConversionFlow(CalculatorState *state);

#endif