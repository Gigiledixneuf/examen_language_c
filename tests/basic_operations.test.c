#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include "../include/basic_operations.h"


#define EPSILON 1e-9


bool nearlyEqual(double a, double b)
{
    return fabs(a - b) < EPSILON;
}


void test_add(void)
{
    double result;

    bool success = add(10.0, 5.0, &result);

    assert(success);
    assert(nearlyEqual(result, 15.0));

    printf("[PASS] add()\n");
}


void test_subtract(void)
{
    double result;

    bool success = subtract(10.0, 5.0, &result);

    assert(success);
    assert(nearlyEqual(result, 5.0));

    printf("[PASS] subtract()\n");
}


void test_multiply(void)
{
    double result;

    bool success = multiply(10.0, 5.0, &result);

    assert(success);
    assert(nearlyEqual(result, 50.0));

    printf("[PASS] multiply()\n");
}


void test_divide(void)
{
    double result;

    bool success = divide(10.0, 5.0, &result);

    assert(success);
    assert(nearlyEqual(result, 2.0));

    printf("[PASS] divide()\n");
}


void test_divide_by_zero(void)
{
    double result;

    bool success = divide(10.0, 0.0, &result);

    assert(!success);

    printf("[PASS] divide() - division par zero\n");
}


void test_null_result(void)
{
    assert(!add(2.0, 3.0, NULL));
    assert(!subtract(2.0, 3.0, NULL));
    assert(!multiply(2.0, 3.0, NULL));
    assert(!divide(2.0, 3.0, NULL));

    printf("[PASS] protection contre NULL\n");
}


int main(void)
{
    printf("=== TESTS DES OPERATIONS DE BASE ===\n\n");

    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_divide_by_zero();
    test_null_result();

    printf("\n=== TOUS LES TESTS SONT PASSES ===\n");

    return 0;
}