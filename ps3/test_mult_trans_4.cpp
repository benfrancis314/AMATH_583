//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2020
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include "Matrix.hpp"
#include "amath583.hpp"

#include "catch.hpp"

#include <cstddef>
#include "Matrix.hpp"
#include "amath583.hpp"

TEST_CASE("Matrix multiply transpose: C = A*B^T 4", "[trans_mult_4]") {
  for (size_t m_rows = 32; m_rows <= 128; m_rows *= 2) {
    Matrix A(m_rows, 64);
    randomize(A);
    Matrix B = transpose(A);
    Matrix C(m_rows, m_rows);
    Matrix D(m_rows, m_rows);
    mult_0(A, B, C);
    mult_trans_4(A, D);
    REQUIRE(f_norm(C-D) < 1.e-12*f_norm(C));
  }
}
