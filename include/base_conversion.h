#ifndef BASE_CONVERSION_H
#define BASE_CONVERSION_H

#include <stdbool.h>

bool isValidBase(int base);

bool convertBase(
    const char *value,
    int initialBase,
    int targetBase,
    char *result,
    int resultSize
);

#endif