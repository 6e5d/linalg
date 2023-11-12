#include <stdio.h>

#include "../include/linalg.h"

int main(void) {
	float v[9] = {-2, -4, 2, -2, 1, 2, 4, 2, 5};
	float vec[9];
	float val[3];
	linalg_eigen(v, vec, val);
	size_t i;
	for (i = 0; i < 3; i++) {
		printf("%f ", (double)val[i]);
	}
	printf("\n");
	for (i = 0; i < 9; i++) {
		printf("%f ", (double)vec[i]);
	}
	printf("\n");
}
