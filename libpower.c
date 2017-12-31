/*
 * libpower.c - Victor Zamora Cruz
 * Bibliotek för att beräkna den totala effektutvecklingen
 * i en krets.
 */
#include <math.h>
#include <stdio.h>
#include "libpower.h"

float calc_power_r(float volt, float resistance)
{
    float power;
    power = pow(volt, 2) / resistance; // P = U² / R kräver -lm växeln vid kompilering
    return power;
}

float calc_power_i(float volt, float current)
{
    float power;
    power = volt * current; // P = U * I
    return power;
}
