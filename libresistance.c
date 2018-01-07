/* libresistance.c  */


#include <stdio.h>

#include "libresistance.h"

float calc_resistance(int count, char conn, float *array)
{
	if (conn != SERIAL && conn != PARALELL) {
		return ERR;
	}
	//Validate input.
	if (count == 0 || !array  || *array == 0){
		return ERR;
	}
	//Värdet 0 skall returneras om något motstånd är noll vid
	//parallellkoppling, dvs  R1||R2=0, om R1 eller R2 är 0Ohm.

	double resistance = 0.0;
	if(conn==SERIAL){
		size_t i = 0;
		for( ; i < count; ++i ) {
			resistance += array[i];
			//printf("added %f to resistance total: %f", array[i], resistance);
		}
	}
	if(conn==PARALELL){
		//(R1+R2)/(R1R2)
		size_t i = 0;
		//1/R1 + 1/R2
		double sum = 0.0;
		//double multip = 1.0;
		for( ; i < count; ++i ){
			sum += 1/array[i];
		}
		resistance = 1/sum;
	}
	return resistance;

}

