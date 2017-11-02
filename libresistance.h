/**
 * Calculate the total resistance of different of different coupled resisitances.
 * The resistances can be coupled in paralell or or serie. 
 * Mixed couplings are not supported. 
 */
#ifndef LIBRESISTANCE
#define LIBRESISTANCE

#define ERR -1
//conn type 'S' = serial
#define SERIAL 'S'
//conn type 'P' = paralell 
#define PARALELL 'P'

/**
 * Parameters
 * count - is amout of components
 * conn is serie or paralell coupled components, SERIAL/PARALELL
 * array is a pointer to array with size of count.
 * 
 * Return
 * Invalid arguments invalid return ERR
 * 0 if resistance is zero or paralell coupling R1||R2=0 or if R1/R2=0Ohm
 */

float calc_resistance(int count, char conn, float *array);

#endif
