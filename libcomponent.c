/* libcomponent */

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "libcomponent.h"

int e_resistance(float orig_resistance,float *res_array) {
	int e12Array[] = {100,120,150,180,220,270,330,390,470,560,680,820};
	int arrayPosition = 0;
	int lowerLimit = -11;
	int upperLimit = 19;
	res_array[0] = 0;
	res_array[1] = 0;
	res_array[2] = 0;
	float smallestValue = e12Array[0]*pow( (float) 10, (float) lowerLimit)*0.9;
	float largestValue = e12Array[11]*pow( (float) 10,(float) upperLimit)*1.1+e12Array[10]*pow( (float) 10,(float) upperLimit)*1.1+e12Array[9]*pow( (float) 10,(float) upperLimit)*1.1;
	bool validValue = neededResistance(orig_resistance,res_array) > smallestValue && neededResistance(orig_resistance,res_array) < largestValue;
	if (validValue) {
		for (int i = upperLimit; i>lowerLimit; i--) {
			for (int rValues = 11; rValues > 0; rValues--) {
				
				float currentResistance = e12Array[rValues]*pow( (float) 10, (float) i); 
				if (currentResistance <= neededResistance(orig_resistance,res_array) && arrayPosition < 3) {
					printf("Added resistance:");
					printf("\%.16f\n",currentResistance);
					res_array[arrayPosition] = currentResistance; 
					arrayPosition ++;
				} 
			}
		}
	} else {
		return ERR;
		//printf("Smallest allowed value: %.16f \n",smallestValue);
        	//printf("Largest allowed value: %.16f \n",largestValue);
	}
	return arrayPosition;
}

float neededResistance(float orig_resistance,float *res_array){
	float result = orig_resistance - res_array[0] - res_array[1] - res_array[2];
	return result;
}


