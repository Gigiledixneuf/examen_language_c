#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdbool.h>

#include "advanced_operations.h"


typedef struct
{
    double result;
    double firstValue;
    double secondValue;

    bool isInitialExecution;

    int currentOperator;
} CalculatorContext;


/*
 * Flux de base
 */
void baseFlow(void);


/*
 * Flux de calculs
 */
void calculationFlow(
    CalculatorContext *context
);


/*
 * Flux d'enchaînement avec
 * le même opérateur.
 */
void sameOperatorFlow(
    CalculatorContext *context
);


/*
 * Flux d'enchaînement avec
 * un opérateur différent.
 */
void differentOperatorFlow(
    CalculatorContext *context
);

#endif