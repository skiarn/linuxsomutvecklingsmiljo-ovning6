/*
 * libpower.c - Victor Zamora Cruz
 * Bibliotek för att beräkna den totala effektutvecklingen
 * i en krets.
 */

#include <stdio.h>

float calc_power_r(float volt, float resistance) {
    float power = 0.0;

    if (resistance <= 0)
    {
        printf("Motstånden måste va större än noll.");
    }
    else power = volt * volt / resistance;
    return power;
}
float calc_power_i(float volt, float current) {
    float power;
    power = volt * current;
    return power;
}
