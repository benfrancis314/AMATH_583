//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2020
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include "test_mult_trans.hpp"

TEST_CASE("Matrix multiply transpose: C = A*B^T 0", "[trans_mult_0]") {
  run_test(mult_trans_3);
}
