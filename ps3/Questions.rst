
PS3 Questions
=============

Add your answers to this file in plain text after each question.  Leave a blank line between the text of the question and the text of your answer.

argv
----

1. What does `argv[0]` always contain?

The file/program in the file system. So in our example, it read out: 
argv[0]: ./repeat.exe

./repeat.exe is not just the file name, which would be repeat.exe, but the file itself, which is: ./repeat.exe
The . represents the current directory, and the / demarcates that repeat.exe is a child of the current directory in the file system tree. 

The ./ is used to help find the program, which otherwise it will not be able to do because it is not in the path. 


2. Which entry of `argv` holds the first argument passed to the program?

argv[1]


3. Which entry of `argv` holds the second argument passed to the program?

argv[2]


4. How would you print just the last argument passed to a program?

argv[argc-1]


float vs double
----------------


5.  What is the difference (ratio) in execution times 
between single and double precision for    *construction with no optimization*? Explain.

Input size 1000000: 
Construction time for float: 64
Construction time for double: 60
Construction ratio: 1.1


Input Size: 10000000
Construction time for float: 563
Construction time for double: 624
Construction ratio: 0.9

Input Size: 50000000
Construction time for float: 2870
Construction time for double: 3085
Construction ratio: 0.93

Input Size: 100000000
Construction time for float: 6523
Construction time for double: 6797
Construction ratio: 0.96

Approximate ratio: 
Around 1. 

Explanation: 
Without optimization, the CPU only fits one float in a word (64 bits). 
So it does not take advantage of the size difference between float and double. 
In general, beyond computer words, floats take half of the size of doubles. If it is not optimized, this will not be taken advantage of. 
During construction, the fixed bandwidth of memory operations will then also take the same time for floats and doubles. 


6.  What is the difference (ratio) in execution times
between single and double precision for    *multiplication with no optimization*? Explain.

Input size 1000000: 
Multiplication time for float: 8
Multiplication time for double: 9
Multiplication ratio: 0.88

Input Size: 10000000
Multiplication time for float: 69
Multiplication time for double: 85
Multiplication ratio: 0.81

Input Size: 50000000
Multiplication time for float: 335
Multiplication time for double: 368
Multiplication ratio: 0.91

Input Size: 100000000
Multiplication time for float: 1274
Multiplication time for double: 4981
Multiplication ratio: 0.25

Appriximate ratio: 
Around 1. 

Explanation: 
As described in the homework notes, in modern processors float operations take the same amount of time as double operations. 
The benefits we will say later are by doing operations on two floats at the same time as one double; but without optimization, we do not see this. 
The discrepency for 100000000 is likely due to read/write cache benefits with float, since it is smaller and thus may be able to be fit into the caches. 


7.  What is the difference (ratio) in execution times 
between single and double precision for    *construction with optimization*? Explain.

Multiplication ratio: 

Input size 1000000: 
Construction time for float: 4
Construction time for double: 11
Construction ratio: 0.36

Input Size: 10000000
Construction time for float: 55
Construction time for double: 96
Construction ratio: 0.57

Input Size: 50000000
Construction time for float: 440
Construction time for double: 933
Construction ratio: 0.47

Input Size: 100000000
Construction time for float: 1889
Construction time for double: 1269
Construction ratio: 1.49

Approximate ratio: 
Around half. 

Explanation: 
With optimization, two floats can be stored in one word (or any other multiple of 64 computational unit), and so memory can be stored and written approxitely twice as fast, if it is optimized to do so. 


8.  What is the difference (ratio) in execution times 
between single and double precision for    *multiplication with optimization*? Explain. 

Input size 1000000: 
Multiplication time for float: 0
Multiplication time for double: 1
Multiplication ratio: Not enough precision (Don't count)

Input Size: 10000000
Multiplication time for float: 8
Multiplication time for double: 18
Multiplication ratio: 0.44

Input Size: 50000000
Multiplication time for float: 72
Multiplication time for double: 174
Multiplication ratio: 0.41

Input Size: 100000000
Multiplication time for float: 364
Multiplication time for double: 1091
Multiplication ratio: 0.33

Approximate ratio: 
Around half. 

Explanation: 
With optimization, two floats can be stored in one word (or analogous computational unit). These can be multiplied at the same time, so arithmetic operations can be done faster. 


9.  What is the difference (ratio) in execution times 
for double precision    multiplication with and without optimization? Explain. 

Input size 1000000: 
Multiplication time w optimization: 1
Multiplication time w/o optimization: 9
Multiplication ratio: 0.11

Input Size: 10000000
Multiplication time w optimization: 18
Multiplication time w/o optimization: 85
Multiplication ratio: 0.21

Input Size: 50000000
Multiplication time w optimization: 174
Multiplication time w/o optimization: 368
Multiplication ratio: 0.47

Input Size: 100000000
Multiplication time w optimization: 1091
Multiplication time w/o optimization: 4981
Multiplication ratio: 0.22

Approximate ratio: 
Around one quarter. 

Explanation: 
The vector registers are 256 bits; with optimization, we can fit four doubles in instead of just one. This explains the approximate quarter ratio. 


All-Pairs
---------

15. What do you observe about the different approaches to doing the similarity computation?  Which algorithm (optimizations) are most effective?  Does it pay to make a transpose of A vs a copy of A vs just passing in A itself.  What about passing in A twice vs passing it in once (mult_trans_3 vs mult_trans_4)?

There is a wide disparity in Gflops, from less than 1 to over 25 (for 128 images). 
The results are different when more images are read. Since the operations are the same, I expect these differences are related to moving the data in and out of memory, 
and related to cache mechanics. 

Which algorithm (optimizations) are most effective?  
The transposes where A is used for both inputs. 
There was a bit of variance in this across multiple runs. 

Does it pay to make a transpose of A vs a copy of A vs just passing in A itself.  
It does pay to just pass in A itself; A can then be kept in a cache and referenced more easily. 
However, experimentally I found a great deal of variance in this, though this is the slight trend. 

What about passing in A twice vs passing it in once (mult_trans_3 vs mult_trans_4)
They are fairly comprable, with both each having slightly better performance on different sizes of input. 

16. What is the best performance over all the algorithms that you observed for the case of 1024 images?  

m_t_3(A,A), with 15.9628 GFlops/s. 
When I ran this another time I got m_t_4(A), and another time got m_t_3(A,C), so it seems to vary; it depends. 
When I ran it a bunch times, the most common one was m_t_4(A). 

What would the execution time be for 10 times as many images?  

The order of execution time, for n images each of size k is: n*n*k = n^2 * k
Then 10 times as many images gives: (10n)*(10n)*k = 100 * n^2 * k, or 100 times as long. 

The size of the matrices would also cause problems. 
The A matrix would be 20480x784=16056320 bytes=16 MB, assuming one byte per data value. 
This will cause cache problems, though blocking will help mitigate this. 
Previously, with 2048 images, the A matrix would be 1.6 MB and so could be kept in the L3 cache, which on my mac is 4MB. 
Now it would not be able to be, though again blocking would help with this. 
The similarity matrix would also be 20480x20480=419430400=419MB~0.4GB, which would require a significant amount of non-cache memory read/write. 

For 60 times as many images?  (Hint: the answer is not cubic but still potentially a problem.) 

60 times as many images gives: (60n)*(60n)*k = 3600 * n^2 * k, or 3600 times as long. 
Also there will be additional time for reading memory, since the matrix will not be able to be stored in cache. 
The A matrix would be 122880x784=96337920=96MB. 
The similarity matrix would be 122880x122880=15099494400=15GB. The computer may not have enough RAM to allocate this; mine only has 8GB. 
Additionally, even if there is enough memory, this will dramatically increase the execution time. 

What if we wanted to do, say 56 by 56 images instead of 28 by 28?
For 28x28 images, our calcuation gives: 
n*n*(28*28), where (28*28) is the vectorized image. 
Here we get: n*n*(56*56) = n*n*(28*2*28*2) = 4 * n^2 *(28*28), which is 4 times as long. 
The size of the matrix A would go from 2048x784 --> 2048x3136 = 6422528 = 6MB. Assuming one byte per data value, since it is an unsigned integer. 
The similarity matrix would then be 3136x3136 = 9834496 = 9 MB. 


About PS3
---------

17. The most important thing I learned from this assignment was ...

Thinking about how the different types of caches can impact algorithm design. 


18. One thing I am still not clear on is ...

The black box of -03; it would be nice to have a more humanly understandable paragraph or so explaining what sort of things happens in it. 


