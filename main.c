/*
 * This will be the main program and is expected to yield the output below.
 */

#include <stdio.h>
#include <stdlib.h>

#include "libresistance.h"
#include "libcomponent.h"
#include "libpower.h"

static void test_case_e12(float res) {
    float *arr = malloc(sizeof(float) * 3);
    printf("Target resistance: %3.1f\n", res);
    printf("count is %d\n", e_resistance(res, arr));
    printf("\t res 1: %3.1f\n", arr[0]);
    printf("\t res 2: %3.1f\n", arr[1]);
    printf("\t res 3: %3.1f\n", arr[2]);
    printf("\t ---------------\n");
    printf("\t sum:   %3.1f\n\n", arr[0]+arr[1]+arr[2]);
    free(arr);
}

int main(void) {
    printf("Ange spänningskälla i V: %d\n", 50);

    char conn = 'S';
    printf("Ange koppling[S | P]: %c\n", conn);

    int nbr_components = 3;
    printf("Antal komponenter: %d\n", nbr_components);

    int i;
    for (i = 0; i < nbr_components; i++) {
        printf("Komponent %d ohm: %d\n", i, i);
    }

    float resistances[] = { 300., 500., 598. };
    float equiv = calc_resistance(nbr_components, conn, resistances);
    printf("Ersättniingsresistans: %3.1f ohm\n", equiv);
    float power_r = calc_power_r(50.f, equiv);
    float current = 50.f / equiv;	
    float power_i = calc_power_i(50.f, current);		
    printf("Effekt: %3.2f W\n", 1.78);

    float *e_res = malloc(sizeof(float) * 3);
    int count = e_resistance(equiv, e_res);
    printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
    for (i = 0; i < count; i++) {
        printf("%3.1f, ", e_res[i]);
    }
    printf("\n\n");
    free(e_res);

    /* Some test cases for E12 replacements */
    /*
    test_case_e12(1398.0f);
    test_case_e12(15.0f);
    test_case_e12(11234.0f);
    test_case_e12(9.0f);
    test_case_e12(24512.0f);
    test_case_e12(14.0f);
    */

    return 0;
}
