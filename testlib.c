#include <stdio.h>
#include "libresistance.h"

void test(int count, const float *array)
{
	if (!array) {
		puts("Null pointer");
	} else {
		printf("%d input values ", count);
		for (int i = 0; i < count; ++i) {
			printf("%3.2f ", array[i]);
		}
	}
	puts("");
	puts("Serial equivalent");
	float sval = calc_resistance(count, 'S', array);
	printf("%3.2f\n", sval);
	puts("Parallel equivalent");
	float pval = calc_resistance(count, 'P', array);
	printf("%3.2f\n", pval);
	puts("");
}

int main(void)
{
	float v0[] = { 0.f, 5e4f };
	test(2, v0);
	float *v1 = NULL;
	test(2, v1);
	float v2[] = { 65e3f, 20e3f, 100e3f, 33e3f };
	test(4, v2);
	float v3[] = { 700.f, -50.f };
	test(2, v3);
	float v4[] = { 0.f/0.f, 100e3f, 33e3f };
	test(3, v4);
	float v5[] = { 1.f/0.f, 1e3f };
	test(2, v5);
	return 0;
}

