Efficiency
----------

10.  If you double the problem size for matrix-matrix product, how many more operations will matrix-matrix product perform?

Approximately 8 times more (on average); this is in accordance with the O(n^3) time complexity. 
2 * n^3 --> 16 * n^3


11.  If the time to perform a given operation is constant, when you double the problem size for matrix-matrix product, how much more time will be required to compute the answer?

Approximately 8 times more (on average)


12.  What ratio did you see when doubling the problem size when mmtime called `mult_0`?  (Hint, it may be larger than what pure operation count would predict.)  Explain.

n = 128 --> t = 2ms
n = 256 --> t = 33ms
n = 512 --> t = 461ms
n = 1024 --> t = 7794ms

Average Ratio: Over 10-20x 

Explanation: 
Smaller problems can be fit into closer caches; so larger inputs will also require more read and write time to memory, which will increase the time beyond what is expected
from the O(n^3) computational complexity. 


13. What ratio did you see when doubling the problem size when mmtime called `mult_3`?  Was this the same for `mult_0`?  Referring to the function in amath583.cpp, what optimizations are implemented and what kinds of performance benefits might they provide?

n = 128 --> t = 0ms
n = 256 --> t = 5ms
n = 512 --> t = 66ms
n = 1024 --> t = 472ms

Average Ratio: Between 8-10x

(Q2) Was this the same for `mult_0`?  
No

(Q3) Referring to the function in amath583.cpp, what optimizations are implemented and what kinds of performance benefits might they provide?
mult_3 uses hoisting, tiling, and blocking, while mult_0 uses none of these. 
Hoisting reduces the number of read/writes to C(i,j). Efficiency goes from 1/3 to 1/2. 
Tiling reduces the number of reads to A and B. Efficiency goes from 1/2 to 2/3. 
Blocking helps with cache efficiency, by splitting the larger matrix problem into subproblems that can each fit entirely in cache. 


14. (Extra credit.)  Try also with `mult_1` and `mult_2`.

mult1: 
n = 128 --> t = 2ms
n = 256 --> t = 32ms
n = 512 --> t = 339ms
n = 1024 --> t = 6952ms

mult2: 
n = 128 --> t = 0ms
n = 256 --> t = 9ms
n = 512 --> t = 90ms
n = 1024 --> t = 2408ms

Mult 1 implements hoisting, and mult 2 implements tiling. 
