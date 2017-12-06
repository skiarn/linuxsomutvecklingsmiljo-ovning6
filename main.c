#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "libresistance.h"
#include "main.h"

/**
Ange spänningskälla i V: 50
Ange koppling[S | P]: S
Antal komponenter: 3
Komponent 1 i ohm: 300
Komponent 2 i ohm: 500
Komponent 3 i ohm: 598
Ersättningsresistans: 1398 ohm
Effekt: 1.78 W
Ersättningsresistanser i E12-serien kopplade i serie: 1200, 180,  18 
 * 
 **/

struct Komponent {
   int  spanning;
};

typedef struct komponent Komponent; 

void printKomponents(struct Komponent list[], int len);
void printKomponent(struct Komponent k );
float * getKomponentsSpanning(struct Komponent list[], int len);

int main(int argc, char *argv[])
{
    int spanning;
    printf("Ange spänningskälla i V: ");
    scanf("%d", &spanning);
    
    char koppling;

    while(true){
        printf("Ange koppling[S | P]: ");
        scanf("%c", &koppling);
        printf("%c: ", koppling);
        if (koppling == 'P' || koppling == 'S' ) {
            break;
        }
    }
    
    int amountOfKomponenter;
    printf("Antal komponenter: ");
    scanf("%d", &amountOfKomponenter);

    struct Komponent komponents[amountOfKomponenter];

    for(int i = 0; i < amountOfKomponenter;  i++){
      struct Komponent k; 

      int tmpSpanning;
      printf("Komponent %d i ohm:", i);
      scanf("%d", &tmpSpanning);
      k.spanning = tmpSpanning;
      komponents[i] = k;
    }

    float ersattningsresistans = calc_resistance(amountOfKomponenter, koppling, getKomponentsSpanning(komponents ,amountOfKomponenter));
    
    printf("Ersättningsresistans: %f ohm\n", ersattningsresistans);
    float effekt = 0.0;
    printf("TODO: Effekt: %f W\n", effekt);
    printf("Ersättningsresistanser i E12-serien kopplade i serie: 1200, 180,  18\n");

	return(RETVALUE);
}

float* getKomponentsSpanning(struct Komponent list[], int len) {
    float *p = malloc(sizeof(float) * len);

    for(int i = 0; i < len;  i++){
       p[i] = list[i].spanning;
    }
    
    return p;
}
void printKomponents(struct Komponent list[], int len) {
    for(int i = 0; i < len;  i++){
        printKomponent(list[i]);
    }
   
}

void printKomponent(struct Komponent k ) {
   printf( "Komponent spänning: %d\n", k.spanning);
}