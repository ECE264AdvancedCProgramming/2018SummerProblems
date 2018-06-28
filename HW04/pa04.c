#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "pa04.h"

int main(int argc, char** argv)
{
   // argv[1]: is the type '-p' for permute function, '-c' for combination function and '-sp' for power sum
   // argv[2]: name of input file
   // argv[3]: for '-c' this value represents the number of items to select
   parse(argc, argv);
}

#ifdef TEST_PER

// This function should print all possible permutations of the strings.
// char * * arr - this is array of strings.
// int len` - the number of strings in `arr`.
void permutation(char * * arr, int len)
{
   //TODO: please implement this function
}

#endif


#ifdef TEST_CMB
// This function should print all possible combinations of the strings.
// char * * arr - this is array of strings.
// int len - the number of strings in `arr`.
// int sel - the number od string to be selected in the example above (Task 2, this is value is 3)
void combination(char * * arr, int len, int sel)
{
   //TODO please implement this function
}

#endif


#ifdef TEST_SUM
// This funcation has to recursively count and print how many ways a number 'k' can be written as a sum of squares
// int k - The number which needs to be expressed as a sum of squares.
void sum_squares(int k)
{
   //TODO please implement this function
}

#endif
