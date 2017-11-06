/*
 * Library for calculating the total power output  in a circuit
 * with a power source connected in series with a resistance.
 */

#ifndef __LIBPOWER_H__
#define __LIBPOWER_H__

float calc_power_i(float volt, float current);
float calc_power_r(float volt, float resistance);

#endif
