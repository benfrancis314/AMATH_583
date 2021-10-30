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
  size_t z_size = z.size();
  Matrix F(sz, z_size);
  Matrix F_T(z_size, sz);
  // Turn it into a matrix
  for (size_t i=0; i < sz; ++i) {
    for (size_t j=0; j< z_size; ++j) {
      F(i,j) = z[j](i);
      F_T(j,i) = z[j](i); // Didn't end up using, but tried this too ... still didn't work
    }
  }

  
  // Replace me with call to cblas_dgemm
  // I'm not sure why this isn't working, I get that Parameter 14 (the last param) is inccorect. However, I feel like this *should* work. 
  // Note: I tried all 8 permutations of sz and z_size for the last three lda ldb and ldc args; it said problem was with last arg
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, sz, z_size, sz, 1.0, &F(0,0), z_size, &F(0,0), sz, 0.0, &C(0,0), sz);

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
