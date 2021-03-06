# Binary Tree

## This is an exercise
In this exercise you will be implementing a way to binary representation which requires you to work with binary trees.  
**do not exclude newline character**.

<strong>Please read the entire file and the comments in the files provided before you ask any question.</strong><br>

# Learning Goals
You will learn to
* Traversals on a binary tree
* Creating binary representation from character values

# Description of exercise
This exercise requires you to do the following :
1. Create an array of elements randomly initialized by a seed passed from the command line. The program has the following command line arguments
	* random_seed 
	* number_of_nodes 
	* output_file_name
	
2. Create a binary search tree by calling the function CreateBST. 
3. Traverse the binary search tree in **post order**. While traversing, if the node currently being visited is not the leaf node save 0. If the node is a leaf node save the value as the ascii value of the data stored in the current node. The data is saved in a binary file whose name is the third argument in the command line.

## Example for this exercise

Let suppose we have a binary tree as follows :

![binary tree](images/binaryTree.png)

Once we have the tree, now we will convert it into its binary representation. We will be using **post-order** traversing.
The exercise requires that all the nodes which are not leaf nodes will have binary value as 0 rest will have the binary value of the of the ascii value of the data.
i.e. for above found tree, the binary representation will be
```
binary(ascii(6)) binary(ascii(\)) 0 0 binary(ascii(n)) binary(ascii({)) 0 0 0

which is (Please mind that there are no spaces, they are just there to make it easy to understand):

00110110 01011100 00000000 00000000 01101110 01111011 00000000 00000000 00000000

```
you can think of it as ![Binary representation](images/printTree.png)

# Functions you need to complete
In this exercise, you have to complete the following functions - `CreateTreeNode`, `CreateBST`,`CreateArrayOfElements`, `saveBST`, `cleanup` and `main()` in `pe06.c`.
**Do not hardcode the name of the files in your code**
1. `CreateTreeNode` -  This function allocates the memory for a particular node and initializes the data of that node to value.
2. `CreateBST` - Takes an array of elements and creates a binary search tree
// from the elements of the array and returns the root of the tree
3. `CreateArrayOfElements` -  This method initializes an array of elements to random values. When testing to make sure the values are repeatable we use the same seed for the random number generator. Use srand and rand to generate the values. Since we want the generated value to lie between 0-255 use %256. 
4. `saveBST` - Traverses the tree in post order fashion and saves the ascii value of the node if the node is a leaf node
else saves 0 (zero). The file is a binary file so use the appropriate function to write to the file.
5. `main()` - In this exercise, your main function has the following the specifications.
  1. if the arguments != 4 then print "Wrong arguments\n" and return
  2. 1st input is long value using random seed needed for the generating the binary search tree
  3. 2nd input is long values - which is number of nodes for the binary search tree
  4. If the random seed or number of nodes input is wrong - Print "Wrong inputs\n" and return EXIT_FAILURE
       For example number of nodes may be input as 12s4 which is not a number in this case you would print "Wrong inputs\n" and return EXIT_FAILURE. Similarly for random seed. (Node random seed can take negative values too)
  5. Create the array using CreateArrayOfElements
  5. Call CreateBST function to get the tree
  6. If tree is has less that 0 nodes (i.e not including 0), then print "Binary Create Failed \n" on the terminal and return EXIT_FAILURE
  7. If the tree has 0 nodes then the file generated should be empty
  8. 3rd input is output filename, in which output needs to be printed
  9. If file read fails, free memory and return EXIT_FAILURE
  10. As described in class, when inserting elements, if the value is the same as that of the root do not insert the node into the tree.

P.S. :  You can check your expected binary files by using the following command :

```
	xxd -b <yourfilename>
```

example, if we run the command on `exp1.bin` file, we get:


```
0000000: 00001011 00110101 00000000 00000000 01110100 00000000  .5..t.
0000006: 11110101 00000000 00000000 00000000                    ....
    
```


The way to read this is: you can ignore the parts `0000000:` and `0000006: `; also ignore `.s..K.` and `5...`. Thus, the binary bits in the file are :

```
00001110 01110011 00000000 00000000 01001011 00000000 00110101 00000000 00000000 00000000

```
 

---------------------
# Testing your code
Following are the files we provide:
1. `pe06.c` - main file for this exercise.


# Checking for memory errors
You should also run ./pe06 with arguments under valgrind. To do that, you have to use, for example, the following command:
```
valgrind --tool=memcheck --verbose --leak-check=full --log-file=expected/valgrind.log ./pe06 23 50 Expected/exp7.bin
```

Note that you should use other input arguments to extensively test your function. If you follow the instructions and keep the malloc and free functions in the right place, you should not have memory problems in this exercise.


# Submitting Your code
**This is a programming exercise, so you would have to submit the code on Blackboard.**

The command to create zip file is as follows:
```

zip HW06.zip pe06.c

```
<strong>You will not get any credits if the submitted file is not zipped</strong>

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


# Grading
If your program has any compilation error or warning (remember to use
`gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror`), you will
receive zero in this exercise.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.

**The grading test cases will be made available along with the grades**
