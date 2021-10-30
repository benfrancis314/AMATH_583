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

// Parallelize, optimize, and cache block me
auto gen_covariance(const std::vector<Vector>& z) {
  size_t sz = z[0].num_rows();
  Matrix C(sz, sz);
  size_t largest_block = 32;
  const int blocksize = std::min(sz, largest_block);

  // Outer loop
  size_t z_size = z.size();
  
  size_t diff = sz % blocksize;

    // Block everything but the fringe
    for (size_t ii = 0; ii < sz-diff; ii += blocksize) {
      for (size_t jj = 0; jj < sz-diff; jj += blocksize) {
        // Inner loop
        for (size_t k = 0; k < z_size; ++k) {
        #pragma omp parallel for
        for (size_t i = ii; i < ii+blocksize; ++i) {
          double t = z[k](i);
          for (size_t j = jj; j < jj+blocksize; ++j) {  
              C(i, j) += t * z[k](j);
          }
        }
      }
      // End inner loop
    }
    }
    // Cover right side of fringe
    for (size_t ii = 0; ii < sz-diff; ii += blocksize) {
      // Inner loop
      for (size_t k = 0; k < z_size; ++k) {
        #pragma omp parallel for
        for (size_t i = ii; i < ii+blocksize; ++i) {
          double t = z[k](i);
          for (size_t j = sz-diff; j < sz; ++j) { 
              C(i, j) += t * z[k](j);
          }
        }
      }       
      // End inner loop
    }
    // Cover bottom side of fringe
    for (size_t jj = 0; jj < sz-diff; jj += blocksize) {
      // Inner loop
      for (size_t k = 0; k < z_size; ++k) {
        #pragma omp parallel for
        for (size_t i = sz-diff; i < sz; ++i) {
          double t = z[k](i);
          for (size_t j = jj; j < jj+blocksize; ++j) {  
              C(i, j) += t * z[k](j);
          }
        }
      }
      // End inner loop
    }
    // Cover the small "square" of fringe in bottom right hand corner
    for (size_t k = 0; k < z_size; ++k) {
      #pragma omp parallel for
      for (size_t i = sz-diff; i < sz; ++i) {
        double t = z[k](i);
        for (size_t j = sz-diff; j < sz; ++j) {  
            C(i, j) += t * z[k](j);
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


const char* tag = "block";

#include "main.hpp"
