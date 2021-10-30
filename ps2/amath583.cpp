//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2020
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include "amath583.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include <cmath>
#include <cstddef>

void zeroize(Vector& x) {
  int num_els = x.num_rows();
  for (size_t i=0; i < num_els; ++i) {
    x(i) = 0;
  }
}

double one_norm(const Vector& x) {
  double sum = 0.0;
  for (size_t i = 0; i < x.num_rows(); ++i) {
    sum += std::abs(x(i));
  }
  return sum;
}

double two_norm(const Vector& x) {
  double sum = 0.0;
  int num_els = x.num_rows();
  for (size_t i = 0; i < num_els; ++i) {
    sum += x(i)*x(i);
  }
  return std::sqrt(sum);
}

double inf_norm(const Vector& x) {
  double max = 0.0;
  int num_els = x.num_rows();
  for (size_t i = 0; i < num_els; ++i) {
    if (std::abs(x(i)) > max) { max = std::abs(x(i)); }
  }
  return max;
}

double dot(const Vector& x, const Vector& y) {
  double sum = 0.0;
  int num_els = x.num_rows();
  for (size_t i = 0; i < num_els; ++i) {
    sum += x(i) * y(i);
  }
  return sum;
}

double two_norm_d(const Vector& x) { 
  return std::sqrt(dot(x,x));  
}

double one_norm(const Matrix& A) {
  double sum = 0.0;
  for (size_t j = 0; j < A.num_cols(); ++j) {    // for each column
    double tmp = 0.0;
    for (size_t i = 0; i < A.num_rows(); ++i) {    // compute column sum
      tmp += std::abs(A(i, j));
    }
    sum = std::max(sum, tmp);
  }
  return sum;
}


double inf_norm(const Matrix& A) {
  double sum = 0.0;
  for (size_t i = 0; i < A.num_rows(); ++i) {    // for each column
    double tmp = 0.0;
    for (size_t j = 0; j < A.num_cols(); ++j) {    // compute column sum
      tmp += std::abs(A(i, j));
    }
    sum = std::max(sum, tmp);
  }
  return sum;
}

// WRITE ME f_norm()

double f_norm(const Matrix& A) {
  double result = 0.0;
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < A.num_cols(); ++j) {
      result += std::abs(A(i,j)) * std::abs(A(i,j));
    }
  }
  return std::sqrt(result);
}

