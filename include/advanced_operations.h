#ifndef ADVANCED_OPERATIONS_H
#define ADVANCED_OPERATIONS_H

#include <stdbool.h>

typedef enum
{
    ANGLE_DEGREES,
    ANGLE_RADIANS
} AngleUnit;


/* Fonctions trigonométriques */

bool calculate_sin(
    double value,
    AngleUnit unit,
    double *result
);

bool calculate_cos(
    double value,
    AngleUnit unit,
    double *result
);

bool calculate_tan(
    double value,
    AngleUnit unit,
    double *result
);


/* Fonctions logarithmiques */

bool calculate_log10(
    double value,
    double *result
);

bool calculate_ln(
    double value,
    double *result
);


/* Fonction exponentielle */

bool calculate_exp(
    double value,
    double *result
);


/* Racine carrée */

bool calculate_sqrt(
    double value,
    double *result
);


/* Puissance */

bool calculate_power(
    double base,
    double exponent,
    double *result
);


/* Factorielle */

bool calculate_factorial(
    double value,
    double *result
);


/* Logarithme à base quelconque */

bool calculate_log_base(
    double value,
    double base,
    double *result
);


/* Racine n-ième */

bool calculate_nth_root(
    double value,
    double n,
    double *result
);

#endif