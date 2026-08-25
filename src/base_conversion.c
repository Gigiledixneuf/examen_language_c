#include "base_conversion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_CONVERSION_DIGITS 64


static bool isSupportedBase(int base)
{
    return base == 2 ||
           base == 8 ||
           base == 10 ||
           base == 16;
}


static int charToDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }

    if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }

    if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }

    return -1;
}


static char digitToChar(int digit)
{
    if (digit < 10)
    {
        return '0' + digit;
    }

    return 'A' + (digit - 10);
}


static bool isValidNumber(
    const char *value,
    int base
)
{
    if (value == NULL || value[0] == '\0')
    {
        return false;
    }

    int start = 0;

    if (value[0] == '-')
    {
        start = 1;

        if (value[1] == '\0')
        {
            return false;
        }
    }

    for (int i = start; value[i] != '\0'; i++)
    {
        int digit = charToDigit(value[i]);

        if (digit < 0 || digit >= base)
        {
            return false;
        }
    }

    return true;
}


static long long convertToDecimal(
    const char *value,
    int base
)
{
    long long result = 0;
    int start = 0;
    int sign = 1;

    if (value[0] == '-')
    {
        sign = -1;
        start = 1;
    }

    for (int i = start; value[i] != '\0'; i++)
    {
        int digit = charToDigit(value[i]);

        result = result * base + digit;
    }

    return result * sign;
}


static void convertFromDecimal(
    long long value,
    int base,
    char *result
)
{
    char buffer[MAX_CONVERSION_DIGITS];

    int index = 0;
    bool negative = false;

    if (value < 0)
    {
        negative = true;
        value = -value;
    }

    if (value == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    while (value > 0)
    {
        int digit = value % base;

        buffer[index++] = digitToChar(digit);

        value /= base;
    }

    if (negative)
    {
        result[0] = '-';
        result++;
    }

    for (int i = 0; i < index; i++)
    {
        result[i] = buffer[index - i - 1];
    }

    result[index] = '\0';
}


bool convert_base(
    const char *value,
    int source_base,
    int target_base,
    char *result,
    int result_size
)
{
    if (value == NULL ||
        result == NULL ||
        result_size <= 0)
    {
        return false;
    }

    if (!isSupportedBase(source_base) ||
        !isSupportedBase(target_base))
    {
        return false;
    }

    if (!isValidNumber(value, source_base))
    {
        return false;
    }

    long long decimalValue =
        convertToDecimal(value, source_base);

    char temporary[MAX_CONVERSION_DIGITS];

    convertFromDecimal(
        decimalValue,
        target_base,
        temporary
    );

    if ((int)strlen(temporary) >= result_size)
    {
        return false;
    }

    strcpy(result, temporary);

    return true;
}