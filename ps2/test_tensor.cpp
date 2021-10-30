#include "Tensor.hpp"
// #define CATCH_CONFIG_MAIN    // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <cstddef>


TEST_CASE("Tensors can be created and initialized", "[Tensor]") {
    Tensor A(30,40,50);
    REQUIRE(A.num_slabs() == 3);
    REQUIRE(A.num_rows() == 4);
    REQUIRE(A.num_cols() == 2);

    SECTION("test initial values") {
        for (size_t i = 0; i < 30; ++i) {
            for (size_t j = 0; j < 40; ++j) {
                for (size_t k = 0; k < 50; ++k) {
                    REQUIRE(A(i, j, k) == 0.0);
                }
            }
        }
        
    }
}
