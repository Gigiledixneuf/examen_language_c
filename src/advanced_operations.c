#include "../include/advanced_operations.h"
#include <stddef.h>

#include <math.h>


#define PI 3.14159265358979323846


static double toRadians(double value, AngleUnit unit)
{
    if (unit == ANGLE_DEGREES)
    {
        return value * PI / 180.0;
    }

    return value;
}


bool calculate_sin(
    double value,
    AngleUnit unit,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    value = toRadians(value, unit);

    *result = sin(value);

    return true;
}


bool calculate_cos(
    double value,
    AngleUnit unit,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    value = toRadians(value, unit);

    *result = cos(value);

    return true;
}


bool calculate_tan(
    double value,
    AngleUnit unit,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    value = toRadians(value, unit);

    /*
     * tan(x) n'est pas définie lorsque cos(x) = 0.
     */
    if (fabs(cos(value)) < 1e-12)
    {
        return false;
    }

    *result = tan(value);

    return true;
}


bool calculate_log10(
    double value,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    if (value <= 0.0)
    {
        return false;
    }

    *result = log10(value);

    return true;
}


bool calculate_ln(
    double value,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    if (value <= 0.0)
    {
        return false;
    }

    *result = log(value);

    return true;
}

bool calculate_exp(
    double value,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    *result = exp(value);

    return true;
}


bool calculate_sqrt(
    double value,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    if (value < 0.0)
    {
        return false;
    }

    *result = sqrt(value);

    return true;
}


bool calculate_power(
    double base,
    double exponent,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    *result = pow(base, exponent);

    return true;
}


bool calculate_factorial(
    double value,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    /*
     * La factorielle est définie ici uniquement
     * pour les entiers naturels.
     */
    if (value < 0.0 || floor(value) != value)
    {
        return false;
    }

    /*
     * Protection contre un résultat trop grand
     * pour un double.
     */
    if (value > 170.0)
    {
        return false;
    }

    double factorial = 1.0;

    for (int i = 2; i <= (int)value; i++)
    {
        factorial *= i;
    }

    *result = factorial;

    return true;
}


bool calculate_log_base(
    double value,
    double base,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    /*
     * Conditions :
     *
     * value > 0
     * base > 0
     * base != 1
     */
    if (value <= 0.0 || base <= 0.0 || base == 1.0)
    {
        return false;
    }

    *result = log(value) / log(base);

    return true;
}


bool calculate_nth_root(
    double value,
    double n,
    double *result
)
{
    if (result == NULL)
    {
        return false;
    }

    /*
     * n doit être strictement positif.
     */
    if (n <= 0.0)
    {
        return false;
    }

    /*
     * Pour une racine paire, une valeur négative
     * n'a pas de résultat réel.
     */
    if (value < 0.0 && fmod(n, 2.0) == 0.0)
    {
        return false;
    }

    /*
     * Cas particulier : racine n-ième de 0.
     */
    if (value == 0.0)
    {
        *result = 0.0;
        return true;
    }

    /*
     * Pour une valeur négative et n impair :
     *
     * racine_n(-a) = -racine_n(a)
     */
    if (value < 0.0)
    {
        *result = -pow(-value, 1.0 / n);
    }
    else
    {
        *result = pow(value, 1.0 / n);
    }

    return true;
}