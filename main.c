/*
 * This will be the main program and is expected to yield the output below.
 */

#include <stdio.h>

int main(void) {
    printf("Ange spänningskälla i V: %d\n", 50);
    printf("Ange koppling[S | P]: %s\n", "S");

    int nbr_components = 3;

    printf("Antal komponenter: %d\n", nbr_components);

    int i;
    for (i = 0; i < nbr_components; i++) {
        printf("Komponent %d ohm: %d\n", i, i);
    }

    printf("Ersättningsresistans: %d ohm\n",1398);
    printf("Effekt: %3.2f W\n", 1.78);
    printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
    for (i = 0; i < nbr_components; i++) {
        printf("%d, ", i);
    }
    printf("\n");
}
