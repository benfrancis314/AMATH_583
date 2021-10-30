//
// This file is part of the course materials for AMATH 483/583 at the University of Washington
// Spring 2021
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include "amath583.hpp"

#include "mkl_cblas.h"

auto gen_covariance(const std::vector<Vector>& z) {
  size_t sz = z[0].num_rows();
  Matrix C(sz, sz);

  // Replace me with call to cblas_dgemm
  for (size_t k = 0; k < z.size(); ++k) {
    for (size_t j = 0; j < C.num_cols(); ++j) {
      for (size_t i = 0; i < C.num_rows(); ++i) {
	C(i, j) += z[k](i) * z[k](j);
      }
    }
  }

  // Normalize
  for (size_t i = 0; i < C.num_rows(); ++i) {
    for (size_t j = 0; j < C.num_cols(); ++j) {
      C(i,j) = C(i,j) / z.size();
    }
  }

  return C;
}

const char* tag = "dgemm";

#include "main.hpp"
