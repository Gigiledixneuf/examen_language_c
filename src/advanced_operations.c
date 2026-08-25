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
