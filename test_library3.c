#include <stdio.h>
#include <stdlib.h>
#include "library3.h"

static void test_case(float res) {
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

    test_case(1398.0f);
    test_case(15.0f);
    test_case(11234.0f);
    test_case(9.0f);
    test_case(24512.0f);
    test_case(14.0f);

    return 0;
}
