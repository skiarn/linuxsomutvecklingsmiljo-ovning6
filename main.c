#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"
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

    float * spanningsList =  getKomponentsSpanning(komponents ,amountOfKomponenter);
    float ersattningsresistans = calc_resistance(amountOfKomponenter, koppling, spanningsList);
    free(spanningsList);

    printf("Ersättningsresistans: %f ohm\n", ersattningsresistans);
    float effekt = calc_power_r(spanning, ersattningsresistans);
    //Multiplicera med 100 och dela med 100.0 för att avrunda nedåt

    printf("Effekt: %.2f W\n", floorf(effekt * 100) / 100);
    float *ersattningsresistorer = malloc(sizeof(float) * 3);
    int resistorerlen = e_resistance(ersattningsresistans, ersattningsresistorer);

    char reslist[80];

    for (int i = 0; i < resistorerlen; i++)
    {
        char tmp[50];
        if (i < resistorerlen -1)
        {
         sprintf(tmp,"%g, ", ersattningsresistorer[i]);
        }
        else
        {
             sprintf(tmp,"%g ", ersattningsresistorer[i]);
        }
        strcat(reslist, tmp);
        }
    printf("Ersättningsresistanser i E12-serien kopplade i serie: %s\n", reslist);

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
