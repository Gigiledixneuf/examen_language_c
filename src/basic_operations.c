#include "../include/basic_operations.h"
#include <stddef.h>

bool add(double a, double b, double *result)
{
    if (result == NULL)
    {
        return false;
    }

    *result = a + b;

    return true;
}


bool subtract(double a, double b, double *result)
{
    if (result == NULL)
    {
        return false;
    }

    *result = a - b;

    return true;
}


bool multiply(double a, double b, double *result)
{
    if (result == NULL)
    {
        return false;
    }

    *result = a * b;

    return true;
}


bool divide(double a, double b, double *result)
{
    if (result == NULL)
    {
        return false;
    }

    if (b == 0.0)
    {
        return false;
    }

    *result = a / b;

    return true;
}