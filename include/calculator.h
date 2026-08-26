#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/advanced_operations.h"

#include <stdbool.h>

typedef struct
{
    double result;
    bool isInitialExecution;
    bool isChainingWithSame;
    int currentOperator;
    double lastBase;
    double lastExponent;
    double lastRootIndex;

    AngleUnit lastAngleUnit;

} CalculatorContext;


/* Flux principaux */

void baseFlow(void);

void calculationFlow(
    CalculatorContext *context
);


/* Flux d'enchaînement */

void sameOperatorFlow(
    CalculatorContext *context
);

void differentOperatorFlow(
    CalculatorContext *context
);

#endif