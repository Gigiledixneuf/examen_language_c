#ifndef BASE_CONVERSION_H
#define BASE_CONVERSION_H

#include <stdbool.h>

/*
 * Convertit une valeur représentée sous forme de chaîne
 * d'une base vers une autre.
 *
 * Bases supportées : 2, 8, 10, 16
 */
bool convert_base(
    const char *value,
    int source_base,
    int target_base,
    char *result,
    int result_size
);

#endif