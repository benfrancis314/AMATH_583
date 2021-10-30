
Final Questions
===============

Eigenfaces
----------

* Given that forming the covariance matrix with 500 images takes approximately 10
seconds, how long (approximately) would forming the covariance matrix take if we used
all 262,781 images in the data file?


Sequential Optimization
-----------------------

* What optimizations did you apply to improve eigenfaces_opt?
Explain why these optimizations would result in better performance.


Parallelization
---------------

* How did you parallelize your code?
On 5000 faces, 
how much speedup were you able to get on 2, 4, 10, and 20 cores (cpus-per-task)?
Does the speedup improve if you load 15000 faces rather than 5000 faces?


Blocking (AMATH 583)
--------------------

* Explain your blocking approach.
On 5000 faces and 10 (or 20) cores (say), 
how much speedup were you able to get over the non-blocked case?
How much speedup were you able to get over the non-blocked case for 50000 face?


DGEMM (Extra Credit)
--------------------

* What single core performance do you get with eigenfaces_dgemm?  
How does your performance scale for 2, 5, 10, 20 cores?  
How does your performance scale with number of faces (500, 5k, 50k)? 
(You may even try 40 cores and 50k or more faces.)


MPI
---

* How does the performance of your eigenfaces_mpi.exe scale for 1, 2, 4, 8 nodes?  (With 10 cores.)


Max
---

* What configuration of nodes and cores per node gives you the very best performance?
(And what was your best performance?)

