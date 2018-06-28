#ifndef PA04_H
#define PA04_H

/*Caution:
 * Do not modify any functions in this file.
 * */

// This function should print all possible permutations of the strings.
// char * * arr - this is array of strings.
// int len` - the number of strings in `arr`.
void permutation(char * * arr, int len);

// This function should print all possible combinations of the strings.
// char * * arr - this is array of strings.
// int len - the number of strings in `arr`.
// int sel - the number od string to be selected in the example above (Task 2, this is value is 3)
void combination(char * * arr, int len, int total_sel);


// This funcation has to recursively count and print how many ways a number 'k' can be written as a sum of squares
// int k - The number which needs to be expressed as a sum of squares.
void sum_squares(int k);

// Parses the input arguments. Calls the correct method depending on the
// input arguments
// argv[1]: is the type '-p' for permute function, '-c' for combination function and '-sp' for power sum
// argv[2]: name of input file
void parse(int argc, char * * argv);

#endif



