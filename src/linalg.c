#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>

#include "../include/linalg.h"

// seems eigen has to be double so we manually copy everything
void linalg(eigen)(float* mat, float* evec, float* eval) {
	double input_data[9];
	double val_data[3];
	double vec_data[9];
	for (size_t i = 0; i < 9; i += 1) {
		input_data[i] = (double)mat[i];
	}
	gsl_matrix_view mat2 = gsl_matrix_view_array(input_data, 3, 3);
	gsl_vector_view eigval = gsl_vector_view_array(val_data, 3);
	gsl_matrix_view eigvec = gsl_matrix_view_array(vec_data, 3, 3);
	gsl_eigen_symmv_workspace *work = gsl_eigen_symmv_alloc(3);
	gsl_eigen_symmv(&mat2.matrix, &eigval.vector, &eigvec.matrix, work);
	gsl_eigen_symmv_free(work);
	for (size_t i = 0; i < 3; i += 1) {
		eval[i] = (float)val_data[i];
	}
	for (size_t i = 0; i < 9; i += 1) {
		evec[i] = (float)vec_data[i];
	}
}
