/*
 * This will be the main program and is expected to yield the output below.
 */

#include <stdio.h>
#include "libresistance.h"

int main(void) {
    printf("Ange spänningskälla i V: %d\n", 50);
    printf("Ange koppling[S | P]: %s\n", "S");
    char conn = 'P';

    int nbr_components = 3;
    printf("Antal komponenter: %d\n", nbr_components);

    int i;
    for (i = 0; i < nbr_components; i++) {
        printf("Komponent %d ohm: %d\n", i, i);
    }

    float resistances[] = { 30., 18., 50. };
    float equiv = calc_resistance(nbr_components, conn, resistances);
    printf("Ersättningsresistans: %f ohm\n", equiv);
    printf("Effekt: %3.2f W\n", 1.78);
    printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
    for (i = 0; i < nbr_components; i++) {
        printf("%d, ", i);
    }
    printf("\n");
}
