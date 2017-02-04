/**
 * @file libresistance.c
 * @author Arvid Axelsson
 * @brief Calculate equivalent resistance of several parallel or serial
 *        connected resistances.
 */
#include "libresistance.h"

static float parallel(int count, const float *array)
{
	double sum_inverses = 0.0;
	for (int i = 0; i < count; ++i) {
		if (array[i] == 0.0) return 0.0f;
		if (array[i] < 0.0) return -1.0f;
		sum_inverses += 1.0 / array[i];
	}
	return 1.0 / sum_inverses;
}

static float series(int count, const float *array)
{
	double sum = 0.0;
	for (int i = 0; i < count; ++i) {
		if (array[i] < 0.0) return -1.0f;
		sum += array[i];
	}
	return sum;
} 

float calc_resistance(int count, char conn, const float *array)
{
	if (!array) {
		return -1.0f;
	}
	float equivalent = 0.0f;

	// Parallel resistances
	if (conn == 'p' || conn == 'P') {
		equivalent = parallel(count, array);
	// Resistances in series
	} else if (conn == 's' || conn == 'S') {
		equivalent = series(count, array);
	} else {
		return -1.0f;
	}
	return equivalent;
}

