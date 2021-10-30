My own question: 
Q: Can both the row and columns be compressed, instead of either-or? 
A: No. One immediate proof of this is that there is a continuous transition between the number of elements in 
"sparse" and "dense" matrices; there is no hard line between how many elements in a matrix make it sparse or dense. 
As such, both dense and sparse representations need to be able to store O(n^2) elements. 
The benefit of compression in *either* row or column storage is that we can make it go from proportional to the number of elements 
to proportional to the number of rows or columns, which is O(n), which is usually less than the number of elements. 
However, the other dimension is still proportional to the number of elements, so the amount of information needed to 
store the matrix values in the row/column indices is still O(n^2). 
If both row and column were compressed, then the amount of information used to store the position of the matrix values would be 
O(n), since both row and column indices would be O(n). 
If we steadily increase the number of elements in our sparse matrix until it is full, we can see that the value position storage is still O(n), 
which is not enough for the O(n^2) number of positions. 
Then there is simply not enough information leftover if we were able to compress the rows and columns, no matter what code we used. 
So the answer is no. 
Note: Saying "never" to these type of things, especially in terms of code efficiency, I assume is either quite the slippery business, or would require
a quite more sophisticated argument. With that said, I think the above constitutes a pretty good, first pass argument for why this cannot be done. 
This is often good enough to quench the curiosity, and to put the possibility of a doubly compressed sparse matrix storage in the "really really hard or maybe impossible" buck of problems. 
Knowing which problems are very hard or impossible is important in its own right. 

(1) How does the performance (in GFLOP/s) for sparse-matrix by vector
product compare to what you previously achieved for dense-matrix by
dense-matrix product?  Explain, and quantify if you can, (e.g., using
the roofline model).

First, we note that the results given are GLOP/s, NOT the total time. Sparse matrix-vector multiplication requires less flops overall, 
which gives them their benefit, even though they have less numerical intensity as measured here. 

The best results here, the CSR/CSC family, performs approximately at the same level of mult_0, which is the unoptimized multiplication. 
However, the sparse matrix methods scale much better; there significant degradataion of GFlops/s with the dense methods, except for mult_3 with blocking. 
The dense methods run into memory problems. There is also a catastrophic loss of time efficiency for dense methods when being run at 1024. 

(2) Referring to the roofline model and the sparse matrix-vector and dense matrix-matrix algorithms, 
what performance ratio would you theoretically expect to see if neither algorithm was able to obtain 
any reuse from cache?

(3) How does the performance (in GFLOP/s) for sparse-matrix by vector
product for COO compare to CSR?  Explain, and quantify if you can,
(e.g., using the roofline model).

COO is approximately half as many GLOP/s as CSR. 

(4) How does the performance (in GFLOP/s) for sparse-matrix by dense
matrix product (**SPMM**) compare to sparse-matrix by vector product
(**SPMV**)? The performance for SPMM should be about the same as for
SPMV in the case of a 1 column dense matrix.  What is the trend with
increasing numbers of columns?  Explain, and quantify if you can,
using the roofline model.

(5) How does the performance of sparse matrix by dense matrix product (in
GFLOP/s) compare to the results you got dense matrix-matrix product in
previous assignments?  Explain, and quantify if you can, using the
roofline model.

