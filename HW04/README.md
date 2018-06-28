# Homework 4 Recursion Exercise

## This is an exercise.
Please read the entire file before you ask any question.

In this exercise you will learn how to use recursion for solving problems



Learning Goals
==============

* Use recursion to solve problems by dividing the problem into smaller problems
* Understand how stack memory works with recursion
* Understand iterative libraries and how they can be implemented

Applications
============
The application for resursion are very many. One such application is permuations and combinations.
Python has a very elegant library for these sort of problems see https://docs.python.org/2/library/itertools.html.
As a part of this exercise we will implement a smaller version of the itertools in C. 

What needs to be done
---------------------
This homework consists of three tasks each performing different functions.

Task 1
------
Write a recursive function whose input is an array of strings i.e `char * *`, and the number of strings, to print
all possible permutations of the strings.

For example:
if the input string array is {"Harry", "Potter", "Was"} i.e it has 3 string.

The output would be

Harry, Potter, Was,\
Harry, Was, Potter,\
Potter, Harry, Was,\
Potter, Was, Harry,\
Was, Potter, Harry,\
Was, Harry, Potter,

Each string needs to be seperated by a comma ',' .Each permuation needs to be followed by a newline character.

Task 2
------
Write a recursive function whose input is an array of strings i.e `char * *`, to compute
all possible combinations of the strings.

The inputs are the string array (i.e. char ** ), the numbers of string and how many are to be chosen out of the number of strings.


For example:
If the input string array is {"Harry", "Potter", "Was", "Written", "By"} has 5 strings. Out of which we need to choose let's say 3.

The output would be

Was, Written, By,\
Potter, Written, By,\
Potter, Was, By,\
Potter, Was, Written,\
Harry, Written, By,\
Harry, Was, By,\
Harry, Was, Written,\
Harry, Potter, By,\
Harry, Potter, Written,\
Harry, Potter, Was,

In this case the order does not matter. By, Potter, Harry is the same as Harry, Potter, By which is the same as By, Potter, Harry and so on.

Each string needs to be seperated by a comma ','. Each permuation needs to be followed by a newline character.

**Hint for Task 1 and Task 2: A very elegant implementation is disscussed in Professor Yung-Hsiang Lu's textbook (The other textbook for the course).**
All students should have access to it. 

See https://www.safaribooksonline.com/library/view/intermediate-c-programming/9781498711647/ or a copy is available at the library (WALC). However you will need to make some changes to apply it to here.


Task 3
------
Task 3 does not deal with iterative tools. Rather its a simple exercise in coming up with a new recursive solution. Task 1 and Task 2 were designed to help you apply and existing solution. Task 3 challenges you to come up with a recursive solution.

You are given a number k. You have to count recursively how many ways k can be written as a sum of squares.
As an example
if k = 10, then 10 can be written as `3^2 + 1^2` so your output will be 1, since there is only one way to express 10 as a sum of squares.
if k = 100. it can be written as `6^2 + 8^2`, `1^2 + 3^2 + 4^2 + 5^2 + 7^2` and as `10^2` so there are three ways. Hence your answer would be 3.


For this homework you will be provided with a argument parser which calls the permuation function is `-p` is passed. Calls the combination function is `-c` is passed. And calls the  power_sum function when `-sq` is passed in the command line.

Functions you need to complete
---------------------------------
In this part you  have to complete the following functions

1.`permutation` - this function should print all possible permutations of the strings.
  * `char * * arr` - this is array of strings.
  * `int len` - the number of strings in `arr`.

2.`combination` - this function should print all possible combinations of the strings.
  * `char * * arr` - this is array of strings.
  * `int len` - the number of strings in `arr`.
  * `int sel` - the number od string to be selected in the example above (Task 2, this is value is 3)

3.`sum_squares` - This funcation has to recursively count and print how many ways a number 'k' can be written as a sum of squares
  * `int k` - The number which needs to be expressed as a sum of squares.

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
code.

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

Testing your code
---------------------------------

You can safely assume that each string will not be larger than 500. 
**As the number of strings grow the time taken to compute goes up factorially. You can be asured that any test executed to grade your code will not require more than 15 seconds. So the number of strings may be quite small**.
If you delete it then your code will not compile.
Following are the files that you will see with the code:
1. pa04.c - main file for this assignment
2. pa04.h - header file, which has definition for the parse function. Please do not modify it.
3. makefile - this is the make file for the assignment. It also has code to test your code for the provided testcases.
4. obj/parse.o - this is the object file, please do not delete it. This object file is generated using a Linux machine
in ECN (i.e., ecegrid).  If you use another other machine, it may not work.
6. test(x).txt - these are some of the generated test cases for you. First line of test1.txt will have number of data points that are in the file. Second line will have dimension of the data point. From 3rd line the data points will start. Please do not modify this file.
7. expected(x).txt - these are the expected output for the test cases given to you.

To test your code. You have to first compile it and the run the following command.
See the make file for more details
```
./pa04 -c Test-Cases/Test/test1.txt 3 > temp.txt
```
1. pa04 - This is binary that should get generated
2. test1.txt - this is the input file which contains data points for which K mean algorithm needs to run
3. 3 - this is no of selections that need to be made
4. output1.txt - this is the name of the file in which output of your algorithm will be written. This will contain the centroids found by the algorithm. You can give any name to it.

Submitting Your code
--------
**This is a programming assignment, so you would have to submit the code on Blackboard**

You have to submit the following file in a zip folder on the blackboard:
* pe04.c - this file should have with above mentioned functions completed.  

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

**As the number of strings grow the time taken to compute and print goes up factorially. You can be asured that any test executed to grade your code will not require more that 15 seconds. So the number of strings may be quite small**.

