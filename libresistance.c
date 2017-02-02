#include "libresistance.h"

float calc_resistance(int count, char conn, const float *array)
{
	if (!array) {
		return -1.0f;
	}
	// Parallel resistances
	if (conn == 'p' || conn == 'P') {
		double sum_inverses = 0.0;
		for (int i = 0; i < count; ++i) {
			if (array[i] == 0.0) return 0.0f;
			if (array[i] < 0.0) return -1.0f;
			sum_inverses += 1.0 / array[i];
		}
		return 1.0 / sum_inverses;
	// Resistances in series
	} else if (conn == 's' || conn == 'S') {
		double sum = 0.0;
		for (int i = 0; i < count; ++i) {
			if (array[i] < 0.0) return -1.0f;
			sum += array[i];
		}
		return sum;
	}
	return -1.0f;
}

