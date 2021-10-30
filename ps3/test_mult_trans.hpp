//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2020
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#ifndef AMATH583_TEST_MULT_TRANS_HPP
#define AMATH583_TEST_MULT_TRANS_HPP

#include "Matrix.hpp"
#include "amath583.hpp"

#include "catch.hpp"

#include <cstddef>
#include "Matrix.hpp"
#include "amath583.hpp"


template <class Fun>
void run_test(Fun f) {
  for (size_t m_rows = 32; m_rows <= 128; m_rows *= 2) {
  const size_t n_cols = 64;
  Matrix A(m_rows, n_cols);
  Matrix B(m_rows, n_cols);
  randomize(A);
  randomize(B);

  Matrix C = transpose(B);
  REQUIRE(f_norm(C) != 0.0);

  Matrix E(m_rows, m_rows);
  Matrix F(m_rows, m_rows);
  REQUIRE(f_norm(E) == 0.0);
  REQUIRE(f_norm(F) == 0.0);

  mult_0(A, C, E);
  f(A, B, F);
  REQUIRE(f_norm(E) != 0.0);
  REQUIRE(f_norm(F) != 0.0);
  REQUIRE(f_norm(E-F) < 1.e-12*f_norm(E));
  }
}

#endif // AMATH583_TEST_MULT_TRANS_HPP
