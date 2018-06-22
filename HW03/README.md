# Clustering Data

## This is an assignment A programming assignment is worth four times of points of an exercise.

*Please read the entire file before you ask any question.*

This assignment asks you to cluster data into groups using the
*mean-shift* algorithm.
Clustering data is one of the most widely used methods in statistical
learning.  This is an example of *unsupervised learning*.

Here are some applications:

* A department store is planning the annual promotion. The store wants
to group customers and give them discounts based on their purchase
history.  The department store sells thousands of products and it is
not possible to manage so many different types of discounts. Instead,
the store wants to provide only 10 types of discounts.

* A social media wants to recommend users to become friends.  The
media use the profiles, such as age, location, work, education,
marital status, to group the users.

* In computer vision, image segmentation is used to partition a digital image into multiple segments.
Segmentation simplifies or changes the representation of an image into something that is more meaningful and easier to analyze.
Mean shift algorithm is one way of achieving this.

This is falls under the category of unsupervised learning because there is no "correct answer" in
advance. In contrast, *supervised learning* means the correct answer
is already known. An example of supervised learning is the [MNIST
Digit
Dataset](https://www.tensorflow.org/get_started/mnist/beginners).  In
this dataset, each image has a correct answer (also called *label*)
between 0 and 9.

Learning Goals
==============

You will learn to
* Understand the mean-shift algorithm and implement it in C.
* Implement memory management in C
* Understand working with valgrind - a simple tool for checking memory
* Write a test generator for creating test cases.
* Develop a strategy for debugging.


Learning Valgrind
-----------------
An important part of mastering C is working with memory allocations and deallocations. We all make mistakes when we code, sometimes even the best 
software programers make mistake of not freeing the memory. But they always check their code before they submit. One of the tool to help you
check the memory management of a C program is valgrind. 

If you have compeleted your HW02, you can try to run `valgrind` on the binary to see its working:

```
  valgrind --tool=memcheck --leak-check=full ./pa03 test1.txt 2 output1.txt
```

You will see lot of output. But important thing is to look for line:
```
  ERROR SUMMARY: 0 errors from 0 contexts
```
If you get this line, then you don't have any memory leaks and probably shouldn't worry. But if you get erros, 
that means there are possible leaks and the tool tell you where you can look for possible errors. 
There are may tutorials that you can search online for
it, one such is [valgrind's](http://valgrind.org/docs/manual/manual-core.html#manual-core.started) 
own documentation. You can search more if you don't find it useful for you


Mean-shift Algorithm
----------------

This assignment uses the *mean-shift clustering* algorithm. This algorithm works in the following way:

1. Read the data points
2. Start with the data points as initial means
3. For each data point, find its neighbours/points which lie within a specified distance.
4. Find the mean of all such neighbours. Update the data point's poistion to the mean
5. Repeat steps 3 and 4 until the convergence condition is met.

This algorithm has many different interpretations. First, it does not
specify how to calculate the distance between a data point and its neighbours.
The data is likely high-dimensional.  The most common
definition is the *Euclidean distance* but other definitions may be
adopted.  Also, the convergence condition can be (a) when no data
point changes to another group, (b) when steps 3-4 have executed a
fixed number of iterations (say 1,000), or (c) something else.

This assignment uses the Euclidean distance and convergence condition is fixed set of iterations.

You can assume that all data points fall within [-1000000, 1000000] in
   each dimension.

Functions you need to complete
---------------------------------
In this part you  have to complete the following functions
`mean_shift`, `allocate_memory` `deallocate_memory`, `get_neighbours` & `find_mean`.  This exercise is relatively easy so that you have enough time to set up
your programming environment. Future homeworks will not be this easy.

1.`allocate_memory` - This function allocates memory for the 2D array data and then return that data.
It accepts the following arguments
  * `no_points`: number of rows for which memory is to be allocated
  * `dim`: number of columns for which memory needs to be allocated

**A word of caution**: Please do not use `x` & `y` for allocating or working with 2D arrays. The memory allocated in a 2D array is in such a way that
  the columns represents `x` and rows represents `y`, leads to errors. Instead use `rows` and `columns` as identifier, it keeps the code clean and understandable.


2.`deallocate_memory` - This function releases the memory of the data. 
  Not completing this function will lead to memory leak. This functions has two arguments
  * `data`: the pointer to data whose memory needs to be freed
  * `no_points`: number of rows that needs to be freed.


3.`get_neighbours` - For a data point, find the closest neighbouring data points which are at a distance lesser than neighbour_distance

  a. Calculate the distance between the data point and to all of the datapoints\
  b. If distance is less than the neighbour_distance\
  c. Return the set of neighbours as a array of pointers (i.e. 2D array)\

  * `const double * datapoint` - the point under consideration
  * `const double * *datapoints` - All the points in the cluster (2D Array, cols = dim, rows = number of points)
  * `int no_points` - the number of rows of the 2D array `double * * datapoints`
  * `int dim` - the number of columns of the 2D array `double * * datapoints`
  * `double neighbour_distance` - the threshold distance above which neighbours are not considered
  * `int* no_neighbours` - returns the number of neighbours by updating the value pointed to by the pointer

4.`find_mean` - This method calculates the weighted mean for all the neighbouring data points.
  * `const double * datapoint`- This is the point for which we are calculating the mean. It is an array of dim elements.
  * `const double * * neighbours` - This is a 2D array of points. Number of rows is no_neighbours. And has dim columns.
  * `int no_neighbours` - This value informs how many neighbours are being considered for the particular datapoint.
  * `int dim` - this is the dimension of the datapoint and neighbours
  * `int weight_factor` - this is the weight factor for the used to calculate the weight, passed to get_weight function

This function will implement the mathematical function below.
Use the get_weight from the header/previous homework

![Weighted Mean equation](/Equations/Mean.png)


5.`mean_shift`- The mean_shift method to cluster data
  * `double * * datapoints`:  two-dimensional array of the data, k rows, dim columns
  * `int k`: the number of data points
  * `int dim`: dimension of the data
  * `int weight_factor`: a number that is used to calculate the weighted mean for each datapoint
  * `int neighbour_distance`: the distance from the datapoint to look for neighbours
  * `int iterations`: number of iterations to be run for
Note that the mean values should be updated onto the datapoints array


Generating testcases
---------------------------------
When developing software, careful planning is the most critical factor
in creating high-quality code.  Testing is an important step but it is
practically impossible to test *every possible* scenario.  The problem
of testing is that for every *branch* (such as `if` condition or `switch`), it is
necessary to test all cases.  Studies show that typical programs have
a branch for every 10 lines of code. If a program has 1,000 lines
(this is a pretty small program), it has 100 branches and
2<sup>100</sup> possible cases.  This is far beyond the capability of
today's fastest computer can do in 100 years.  Thus, instead of
performing *exhaustive test* (i.e., test every possible case), it is
important to test strategically and create test cases carefully.

This assignment shows you *one way* (definitely not the only way) to
generate test cases.

This is an important part of your learning. Generating many testcases to check everything is very important to you. To generate the test cases, you can think in the following way
1. Think of expected mean in some range, let's says between [-100,100]
2. Let's say the number of means you want for mean-shift algorithm is 3, and for this example we make it 2-dimensional.
3. Split the range selected into k means eg. for 3 means evenly distrubed in the range eg.((-33.33, -33.33), (33.33, 33.33) , (100, 100))
4. Generate random points around those means. To do this you can follow the following procedure:
	* first generate a random number between 0 & 1.
	* now subtract 0.5 from the above number, thus the range of this random number will now be between [-0.5, 0.5]
	* multiply this random number with range/(k+1) eg. in above case it will be 100/(3+1)
	* add the above number to the means that we selected earlier eg. (-33.3 + random * range/(k+1), -33.3 + random * range/(k+1)). This will create a single point around first mean. Similary you can generate points around other means.

Generating testcases
---------------------------------
Please follow the same steps as in HW02 for Generating testcases for this assignment too. 
You can also use TestGenerator that is being provided to you.

Testing your code
---------------------------------
Please do not delete the obj folder, it contains the `euclid_distance.o` file which has `euclid_distance` function and `get_weight.o` file which has `get_weight` function. It is given to you for Homework 3, if you were not able to complete in HW02. If you delete it then your code will not compile.

Following are the files that you will see with the code:
1. pa03.c - main file for this assignment
2. pa03.h - header file, which has definition for `euclid_distance` and `get_weight` function. Please do not modify it.
3. makefile - this is the make file for the assignment. It also has code to test your code for the provided testcases.
4. obj/euclid_distance.o - this is the object file, please do not delete it. This object file is generated using a Linux machine
in ECN (i.e., ecegrid).  If you use another other machine, it may not work.
5. obj/get_weight.o - this is another object file has implementation of get_weight function. This object file is generated using a Linux machine in ECN (i.e., ecegrid).  If you use another other machine, it may not work. 
6. test(x).txt - these are some of the generated test cases for you. First line of test1.txt will have number of data points that are in the file. Second line will have dimension of the data point. From 3rd line the data points will start. Please do not modify this file.
7. expected(x).txt - these are the expected output for the test cases given to you.

To test your code. You have to first compile it and the run the following command.

```
./bin/pa03 test1.txt output1.txt
```
1. `pa03` - This is binary that should have generated after compilation
2. `test1.txt` - this is the input file which contains data points for which K mean algorithm needs to run
3. `6` - this is the value of `K`, this should be same as what used which generating test1.txt file
4. `output1.txt` - this is the name of the file in which output of your algorithm will be written. This will contain the means found by the algorithm. You can give any name to it.


Getting different answer?
---------
Your answer may be different from ours due to several reasons. 
Floating points have finite precision; thus, the computation results
may depend on the order of calculation.  You need to think carefully
about whether your program is correct if the results are different
from the sample outputs given by the teaching staff

Submitting Your code
--------
**This is a programming assignment, so you would have to submit the code on Blackboard**

You have to submit the zip file containing `pa03.c` on the blackboard: 
* `pa03.c` - this file should have with the above specified functions completed.  

To create zip file on terminal, you can use the `zip` command in the following way:
```
 zip <filename>.zip pa03.c
```
To know the location/path of the folder that you are in, you can use `pwd` on terminal
```
pwd
```

Following commands will be helpful if you are using remote terminal and want to copy code to your local machine:

To copy code from a remote machine to your local machine:
* Open terminal in your local machine
* `cd` to the folder in your local machine to which you want to copy the file
* Use `scp` command to get the file to your local machine. See below for details
```
scp username@<remote machine>:<path to the file>/filename .
```

This copies the file to your current folder. eg. if I am working on a remote machine at ecegrid-thin1.ecn.purdue.edu, 
and my file is `pa03.c` at the location /home/min/a/abc/2018Spring/, then I will use the following command :

```
scp abc@ecegrid-thin1.ecn.purdue.edu:/home/min/a/abc/2018Spring/pa03.c .
```
Please note that end of the command has `.`. This in linux commands refers to present folder.

The **only** way to submit homework is through Blackboard.

The instructor will **never** accept any requestion for exception "*my
submission is only one minute late*".  It is your responsibility to
meet the deadline.  You are strongly encouraged to submit at least ten
minutes before the deadline because submission may take time.

If there is a campus-wide problem (such as network outage or the
Blackboard server is down), the deadline will be extended for the
entire class. If the problem is specific to yourself (for example,
your computer crashes), the deadline will not be extended for
you.

**DO NOT** send your code by email. Your code will not be graded
  if it is sent by email.

The teaching staff is strictly prohibited to look at files on your
computer (or your Purdue account) for grading. Thus, **NEVER** say "I
finished before the deadline but I forgot to submit".  **NEVER** say "I have
not made any change after the submission deadline." because the
teaching staff is not allowed to look at your files that have not been
submitted through Blackboard.


Grading
-------

If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

If your program gives memory leaks i.e. fails valgrind test, 
we will deduct marks. Remember to always free the memory you have allocated. This
is an important trait of a good C programmer.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.  

This assignment has given you many test cases.  It is possible (and
likely) that additional test cases will be used for grading.  If your
program passes  some test cases and
fails the others, the score will be proportional to the number of
passed test cases.


Comment Your Code
-----------------

ECE 264 does not grade your comments because you *should* write
comments for your own benefits.  You do many things (such as eating
dinner or exercise) even though you receive no point from any course.
Writing comments is the same. You need to do it because it is good for
you.


Grading
-------

If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this assignment.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.  

This assignment has given you many test cases.  It is possible (and
likely) that additional test cases will be used for grading.  If your
program passes  some test cases and
fails the others, the score will be proportional to the number of
passed test cases.
