// void handleUserKeywordInput();
// void showTitle();

#ifndef INTERFACE_H
#define INTERFACE_H

#include "../include/calculator.h"

typedef struct
{
    bool isBasic;
    bool isTrigo;
    bool isUnary;
    int position;
} Operator;

void showTitle(void);

int getOperatorChoice(void);

Operator defineOperator(int p);
#endif