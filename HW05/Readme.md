# HW05. Student Database SQL

<strong>Please read the entire file before you start working on this assignment.</strong><br>

In this an **assignment** you will build your own linked list data structure and simple student database. 
This assignment takes time. You should start early.

## Learning Goals
* Understand linkedlist.
* Understand structures
* Understand files
* Deepen your understanding of pointers and memory addresses.
* Deepen your understanding of memory allocation and deallocation.


## LinkedList
 Linked list is a data structure consisting of a group of nodes which together represent a sequence or a chain. Each node has a link or a pointer to the next node in the chain except for the last node (tail) in the linkedlist which is pointing at NULL. The first node in the linkedlist is the head node.
 
 Why linkedlist?
 - Nodes don't have to be stored in contiguous memory locations.
 - The allocation is dynamic not static. The size of the linkedlist can be changed during the running time of the program (the size is not required to be known in advance).
 - insertion at (or deletion from) any position in constant time.

About the assignment
---------------------
For this assignment we will build a simple student SQL database.
We will implement a simple version of SQL
We have three fields in our database. Student `Id`, `name` and `year` (see database.txt). 
What we can do with SQL is select some of the nodes in the database based on a condition using the WHERE keyword. Also SQL allows us to sort the selected data using the SORT_BY keyword.
For example if the student database has three noes/items

1,Vettel,21\
2,Mansell,23\
3,Clark,28

We can use the `SORT_BY` command to sort it by `NAME`
We can type `SORT_BY NAME` and the output will be 
3,Clark,28\
2,Mansell,23\
1,Vettel,21

To this we can add a selection criteria by using WHERE
`SORT_BY NAME WHERE ID “>” 1`, this will output the following
3,Clark,28\
2,Mansell,23

**Implementation**
The logic is to first build a linked list for each of the elements in the database.
Then use the selection criteria to delete all the noes in the list that are not selected and finally sort this “select phase” list and print it.

So this assignment provides the 
1. Parsing function which parses all of the inputs into appropriate structs
2. A bubble sort function to sort the list
3. A function to print the list

**“25% bonus points for implementing your own sort function using quick sort”. If you do attempt the bonus points question include the function in a separate file when submitting the code and name the file “bonus.c”**


Functions you need to complete
---------------------------------
In this part you  have to complete the following functions.
You have to complete the following functions:
* `main` - See pa05.c on what to do and how to complete the main function
* `int compare_year(const void* a, const void* b)` - This function is of the "compare_fptr" function pointer. This will be assigned to the Parse->compare by the parse function if the sort is to be done by year. If the return value is less than 0 The element pointed by 'a' goes before the element pointed by 'b', else if it's equal to 0 The element pointed by 'a' is equivalent to the element pointed by 'b'. Else if it's greater than 0 The element pointed by 'a' goes after the element pointed by 'b'.

* `int compare_name(const void* a, const void* b)` -  This function is of the "compare_fptr" function pointer. This will be assigned to the Parse->compare by the parse function if the sort is to be done by name

* `bool select_year(Student* node, const void* value, bool greater)` -This is a function whose type matches that of the "sel_func" function pointer. It will be assigned to the Parse->selecrt->sel_func by the parse function if the selection is to be by year \
Inputs: \
`Student* node`: the node which needs to be selcted by the select process or not \
`value`, holds the value to be compared ex. if the command was WHERE ">" 25, value is 25 \
`greater` is true is the command was ">" else greater is false when the command is "<" \
Return value \
If the node satisfies the condition then return true i.e select the node else if it's not to be selected return false

* `bool select_name(Student* node, const void* value, bool greater)` -This is a function whose type matches that of the "sel_func" function pointer. It will be assigned to the Parse->selecrt->sel_func by the parse function if the selection is to be by name \
Inputs: \
`Student* node`: the node which needs to be selcted by the select process or not \
`value`, holds the value to be compared ex. if the command was WHERE ">" 25, value is 25 \
`greater` is true is the command was ">" else greater is false when the command is "<" \
Return value \
If the node satisfies the condition then return true i.e select the node else if it's not to be selected return false

* `Node* build_list(char* filename)` - Read from the file "filename", create a list of Node* and return head of the list.
Tip: Its probably useful to break this function down into smaller functions

* `void destroy_list(Node* h)` - Free the list pointed to by the head node h.
Keep in mind to do the following. Firstly, free node->data->name next free node->data
and finally free the node.

* `Node* select_phase(Select* select, Node* std_list)` -
Note that the Node struct has a selected bool, and set the bool to true if select->sel_func returns true else false.
If the node is not to be selected then you have two choices 
1) delete that node from the list 
2) or while printing only print the selected nodes \
Note: if you choose option 2 you will need to write your own print list method

Submitting your code
---------------------------------
Type the following command to zip your file.
```bash
	zip pa05.zip pa05.c
```
<strong>You will not get any credits if the submitted file is not zipped</strong>

**If you do attempt the bonus points question include the function in a separate file when submitting the code and name the file “bonus.c”**

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
receive zero in this assignment.

In absolutely no circumstance can the teaching staff modify your
program for grading.  You cannot say, "If you change this, my program
works." If your program misses a semicolon and cannot compile, you
will receive zero.  Your score depends on what is submitted, nothing
else.



**All Test cases will be released later.**

