
PS2 Questions
=============

Add your answers to this file in plain text after each question.  Leave a blank line between the text of the question and the text of your answer and at least two lines between your answer and the next question.

.. role:: cpp(code)
   :language: c++


Inner Product
-------------

1. How would you use :cpp:`dot` to implement :cpp:`two_norm`?

The two norm of a vector is the square root of its dot product with itself. 
So I would do: (and did this in amath583.cpp)

double two_norm_d(const Vector& x) { 
  return std::sqrt(dot(x,x));  
}

Tensors
-------

2. What is the formula that we would use for indexing if we wanted "slab-major" ordering?  Hint:  What is the size of a slab?  It might be helpful to draw a picture of the data in 3D and see what the size is of a slab.

Let us define the slab index value to be i, the row index value to be j, and the column index value to be k. 
Also, let us call the number of slabs to be num_slabs, the number of rows to be num_rows, and the number of columns to be num_cols. 

Slab-major ordering vectorizes each slab, and lays them out one after the other. 
So the tensor would be: 
[ SLAB1 , SLAB2, SLAB3, ... ]

Each individual slab then looks like a matrix. As such, there is flexibility between having each slab stored as row-major or column-major. 
This is explored in the extra credit question. 
I will proceed by assuming each slab is row-major. 

Then  the indexing formula is: 
((j*num_cols) + k) + (num_cols*num_rows)*i

Notice this is like our older row-ordering for matrices, but with the additional term for the slabs. 

Another way of visualizing this, replacing SLAB by [ROW ROW ROW ...] is: 
[ [ROW ROW ROW ... ] [ROW ROW ROW ... ] [ROW ROW ROW ... ] ... ]


3. (Extra credit.) I claim that there are six distinct indexing formulas.  Show that this claim is correct or that it is incorrect.
This is correct; indexing (a single element) requires specifying one value for each of the dimensions in the tensor. 
Since the tensor has three dimensions, named "slabs", "rows", and "columns", one value must be specified for each. 
However, the order of this specification is arbitrary. One could just as well provide the slab number, row number, and column number, 
or the row number, column number, and slab number. Calling the slab number S, the row number R, and the column number C, this gives six possible
indexing formulas: 
   1. SRC
   2. SCR 
   3. RSC
   4. RCS
   5. CSR
   6. CRS
This is also 3*2*1 = 3! = 6 possible results. 
Then you are correct, there are six distinct indexing formulas. 

