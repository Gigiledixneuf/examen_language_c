#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "../include/advanced_operations.h"

#define PI 3.14159265358979323846


#define EPSILON 1e-9


static bool nearlyEqual(double a, double b)
{
    return fabs(a - b) < EPSILON;
}


void test_sin_degrees(void)
{
    double result;

    bool success = calculate_sin(
        30.0,
        ANGLE_DEGREES,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 0.5));

    printf("[PASS] sin(30°)\n");
}


void test_sin_radians(void)
{
    double result;

    bool success = calculate_sin(
        PI / 6.0,
        ANGLE_RADIANS,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 0.5));

    printf("[PASS] sin(pi/6)\n");
}


void test_cos_degrees(void)
{
    double result;

    bool success = calculate_cos(
        60.0,
        ANGLE_DEGREES,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 0.5));

    printf("[PASS] cos(60°)\n");
}


void test_cos_radians(void)
{
    double result;

    bool success = calculate_cos(
        PI / 3.0,
        ANGLE_RADIANS,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 0.5));

    printf("[PASS] cos(pi/3)\n");
}


void test_tan_degrees(void)
{
    double result;

    bool success = calculate_tan(
        45.0,
        ANGLE_DEGREES,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 1.0));

    printf("[PASS] tan(45°)\n");
}


void test_tan_radians(void)
{
    double result;

    bool success = calculate_tan(
        PI / 4.0,
        ANGLE_RADIANS,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 1.0));

    printf("[PASS] tan(pi/4)\n");
}


void test_tan_undefined(void)
{
    double result;

    bool success = calculate_tan(
        90.0,
        ANGLE_DEGREES,
        &result
    );

    assert(!success);

    printf("[PASS] tan(90°) - valeur indefinie\n");
}


void test_trigonometric_null_result(void)
{
    assert(!calculate_sin(
        30.0,
        ANGLE_DEGREES,
        NULL
    ));

    assert(!calculate_cos(
        30.0,
        ANGLE_DEGREES,
        NULL
    ));

    assert(!calculate_tan(
        30.0,
        ANGLE_DEGREES,
        NULL
    ));

    printf("[PASS] fonctions trigo - protection NULL\n");
}


void test_log10(void)
{
    double result;

    bool success = calculate_log10(
        1000.0,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 3.0));

    printf("[PASS] log10(1000)\n");
}


void test_log10_one(void)
{
    double result;

    bool success = calculate_log10(
        1.0,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 0.0));

    printf("[PASS] log10(1)\n");
}

void test_log10_invalid(void)
{
    double result;

    assert(!calculate_log10(0.0, &result));
    assert(!calculate_log10(-10.0, &result));

    printf("[PASS] log10 - valeurs invalides\n");
}



void test_ln(void)
{
    double result;

    bool success = calculate_ln(
        exp(1.0),
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 1.0));

    printf("[PASS] ln(e)\n");
}


void test_ln_one(void)
{
    double result;

    bool success = calculate_ln(
        1.0,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 0.0));

    printf("[PASS] ln(1)\n");
}

void test_ln_invalid(void)
{
    double result;

    assert(!calculate_ln(0.0, &result));
    assert(!calculate_ln(-10.0, &result));

    printf("[PASS] ln - valeurs invalides\n");
}

void test_logarithm_null_result(void)
{
    assert(!calculate_log10(10.0, NULL));
    assert(!calculate_ln(10.0, NULL));

    printf("[PASS] logarithmes - protection NULL\n");
}


void test_exp(void)
{
    double result;

    bool success = calculate_exp(
        1.0,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, exp(1.0)));

    printf("[PASS] exp(1)\n");
}


void test_exp_negative(void)
{
    double result;

    bool success = calculate_exp(
        -1.0,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, exp(-1.0)));

    printf("[PASS] exp(-1)\n");
}


void test_exp_null_result(void)
{
    assert(!calculate_exp(1.0, NULL));

    printf("[PASS] exp - protection NULL\n");
}


void test_sqrt(void)
{
    double result;

    bool success = calculate_sqrt(
        25.0,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 5.0));

    printf("[PASS] sqrt(25)\n");
}


void test_sqrt_zero(void)
{
    double result;

    bool success = calculate_sqrt(
        0.0,
        &result
    );

    assert(success);
    assert(nearlyEqual(result, 0.0));

    printf("[PASS] sqrt(0)\n");
}


void test_sqrt_negative(void)
{
    double result;

    assert(!calculate_sqrt(-1.0, &result));

    printf("[PASS] sqrt(-1) - valeur invalide\n");
}

void test_sqrt_null_result(void)
{
    assert(!calculate_sqrt(25.0, NULL));

    printf("[PASS] sqrt - protection NULL\n");
}

int main(void)
{
    printf("=== TESTS DES FONCTIONS TRIGONOMETRIQUES ===\n\n");

    test_sin_degrees();
    test_sin_radians();

    test_cos_degrees();
    test_cos_radians();

    test_tan_degrees();
    test_tan_radians();

    test_tan_undefined();

    test_trigonometric_null_result();


    test_log10();
test_log10_one();
test_log10_invalid();

test_ln();
test_ln_one();
test_ln_invalid();

test_logarithm_null_result();

    printf("\n=== TOUS LES TESTS SONT PASSES ===\n");



    return 0;
}