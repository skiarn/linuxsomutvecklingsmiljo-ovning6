/**
 * Calculate replacement resistance using the e12-series (+/- 10 % tolerance)
 * Values much greater than 10^12 is not supported.
 * Values much smaller than 10^-8 is not supported.
**/

#ifndef LIBCOMPONENT
#define LIBCOMPONENT

#define ERR -1


/**
 * Parameters
 * orig_resistance - resistance that should be replaced
 * *res_array - array pointer to resistors required to replace orig_resistance
 *
 * Return
 * Invalid orig_resistance will return ERR
*/

int e_resistance(float orig_resistance,float *res_array);



/**
 * Parameters
 * orig_resistance - resistance that should be replaced
 * *res_array - array pointer to resistors required to replace orig_resistance
 *
 * Return
 * resistance needed by the replacement resistor(s)
*/

float neededResistance(float orig_resistance,float *res_array);


#endif
