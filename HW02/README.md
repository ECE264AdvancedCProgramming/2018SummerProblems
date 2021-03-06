# Clustering Data

## This is an exercise. HW03 will extend this program as a programming assignment. A programming assignment is worth four times of points of an exercise.

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
* Comment your code.
* Learn how to write a test generator for creating test cases.
* Inspect the details of a program's progress
* Develop a strategy for debugging.

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


Comment Your Code
-----------------

Many (probably most) students write comments because they are required
by instructors. Moreover, many (probably most) students write comments
*after* they write code and they know clearly this is wrong.  Students
know that they need to write comments *before* writing code.

ECE 264 does not grade your comments because you *should* write
comments for your own benefits.  You do many things (such as eating
dinner or exercise) even though you receive no point from any course.
Writing comments is the same. You need to do it because it is good for
you.

The problem is that many instructors tell students to comment code but
these instructors never tell students *how to* comment code.  Many
professors never write comments in the code given to students.  As a
result, many students comment code incorrectly.

Comments should help readers understand code.  That means comments
should provide information that is not easily understood by reading
code.  The following is an example of a good comment:

```
int main(int argc, char * * argv)
{
    // argv[1]: dimension
    // argv[2]: number of data points
}
```
This is another example of useful information

```
int func(int a, int b)
{
    // a must be greater than b
}
```

The following is an example of a bad comment because it provides
no information

```
int main(int argc, char * * argv)
{
    if (argc != 3)
    {
         return EXIT_FAILURE;
	 // if argc is not 3, stop the program
    }
}
```
This is another example of useless comment


```
int func(int a, int b)
{
    // the function takes two integers as input arguments
    // and returns an integer
}
```

You should read the files given to you carefully and use them
as samples for writing comments.


Functions you need to complete
---------------------------------
This is the first part of your assignment for the mean-shift algorithm. In this part you  have to complete only
two functions - `euclid_distance` & `get_weight`.  This exercise is relatively easy so that you have enough time to set up
your programming environment. Future homeworks will not be this easy.

1. `euclid_distance` - this function calculates the Euclidean distance between the mean and the data point. It has three arguments as inputs `const double * datapoint`, `const double * mean` & `int dim` 
  * `const double * datapoint` - this is a pointer (an array of `dim` elements) to datapoint from which distance needs to be calculated. It is const because we don't want the function to change the value of data.
  * `double * mean` - As the name suggests this is pointer to the mean, which has `dim` elements.
  * `int dim` - this is the dimension of the datapoint.

You will be implementing this formula in this `euclid_distance` function

![Euclidean distance equation](/Equations/EuclideanDistance.gif)

**Note that x is an n-dimensional point, where the number of dimensions are given by `dim`** 

2. `get_weight` - This function is needed to find the weight for the weighted mean that we be performed to calculate the mean.
  * `double distance` - this is the distance of the point from the mean.
  * `int weight_factor` - this is the weight factor for the used to calculate the weight see the formula below
This function will be implementing the follwoing function

![Weight equation](/Equations/WeightEquation.png)

where Wfactor is is `weight_factor`, e is the mathematical constant.

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


Testing your code
---------------------------------
Please do not delete the obj folder, it contains the mean_shift.o file which has `mean_shift` function and mem_mgmt.o file which has `allocate_memory` and `release_memory` functions.  It is given to you for Homework 2.

You need to write
these function in Homework 3.
If you delete it then your code will not compile.
Following are the files that you will see with the code:
1. pe02.c - main file for this assignment
2. pe02.h - header file, which has definition for other functions. Please do not modify it.
3. Makefile - this is the make file for the assignment. It also has code to test your code for the provided testcases.
4. obj/mean_shift.o - this is the object file, please do not delete it. This object file is generated using a Linux machine
in ECN (i.e., ecegrid).  If you use another other machine, it may not work.
5. obj/mem_mgmt.o - this is another object file that has memory managment function. This object file is generated using a Linux machine
in ECN (i.e., ecegrid).  If you use another other machine, it may not work. 
6. test(x).txt - these are some of the generated test cases for you. First line of test1.txt will have number of data points that are in the file. Second line will have dimension of the data point. From 3rd line the data points will start. Please do not modify this file.
7. expected(x).txt - these are the expected output for the test cases given to you.

To test your code. You have to first compile it and the run the following command.

**Note running all the test cases provided may take several minutes. So use the first few testcases to debug your code. Once you are confident run all the testcases**
To test all cases type `make test`

```
./bin/pe02 test1.txt output1.txt
```
1. pe02 - This is binary that should get generated. A folder called 'bin' will be generated and the binary will be placed within that folder
2. test1.txt - this is the input file which contains data points for which K mean algorithm needs to run
3. output1.txt - this is the name of the file in which output of your algorithm will be written. This will contain the means found by the algorithm. You can give any name to it.

Submitting Your code
--------
**This is a programming assignment, so you would have to submit the code on Blackboard**

You have to submit the following file in a zip folder on the blackboard:
* pe02.c - this file should have with `euclid_distance` and `get_weight` function completed.  

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

I will try and respond to your emails, but due to the shear amount of emails,
I cannot guarantee a quick response. **Your code will not be graded
  if it is sent by email.**

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
