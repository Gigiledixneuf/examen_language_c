#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdbool.h>

typedef struct
{
    bool isBasic;
    bool isTrigo;
    bool isUnary;
    int position;
} Operator;


void showTitle(void);

void showOperationsMenu(int actualPosition);

Operator defineOperator(int position);

int getOperatorChoice(void);

#endif