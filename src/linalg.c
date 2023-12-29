#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>

#include "../include/linalg.h"
#define GslMatrixView gsl_matrix_view
#define GslVectorView gsl_vector_view
#define GslEigenSymmvWorkspace gsl_eigen_symmv_workspace

// seems eigen has to be double so we manually copy everything
void linalg(eigen)(float* mat, float* evec, float* eval) {
	double input_data[9];
	double val_data[3];
	double vec_data[9];
	for (size_t i = 0; i < 9; i += 1) {
		input_data[i] = (double)mat[i];
	}
	GslMatrixView mat2 = gsl_matrix_view_array(input_data, 3, 3);
	GslVectorView eigval = gsl_vector_view_array(val_data, 3);
	GslMatrixView eigvec = gsl_matrix_view_array(vec_data, 3, 3);
	GslEigenSymmvWorkspace *work = gsl_eigen_symmv_alloc(3);
	gsl_eigen_symmv(&mat2.matrix, &eigval.vector, &eigvec.matrix, work);
	gsl_eigen_symmv_free(work);
	for (size_t i = 0; i < 3; i += 1) {
		eval[i] = (float)val_data[i];
	}
	for (size_t i = 0; i < 9; i += 1) {
		evec[i] = (float)vec_data[i];
	}
}
