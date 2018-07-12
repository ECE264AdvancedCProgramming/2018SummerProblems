#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode 
{
	unsigned char data;
	struct TreeNode *leftChild;
	struct TreeNode *rightChild;
} TreeNode;

#ifndef TEST_CREATE_TREE_NODE
// CreateTreeNode allocates the memory for a particular node
// and initializes the data of that node to value
TreeNode* CreateTreeNode(unsigned char value)
{
	// TODO: Complete this method
	return NULL; // Dummy value, feel free to rewrite this function completely
}

#endif


#ifndef TEST_CREATE_BST
// Takes an array of elements and creates a binary search tree
// from the elements of the array and returns the root of the tree
TreeNode* CreateBST(unsigned char *array, int len)
{
	// TODO: Complete this method
	return NULL; // Dummy value, feel free to rewrite this function completely
}

#endif

#ifndef TEST_CREATE_ARRAY
// This method initializes an array of elements to random values.
// When testing to make sure the values are repeatable we use the same seed for the random number generator
// use: "srand(randomSeed);" to seed the random number generator
// use "rand() % 256;" to generate the value since we want the generated value to lie between 0-255
// since unsigned char can only store values from 0 - 255 
unsigned char* CreateArrayOfElements(long randomSeed, long len)
{
	// TODO: Complete this method
	return NULL; // Dummy value, feel free to rewrite this function completely
}

#endif

#ifndef TEST_SAVE
// Input arguments: root node of the tree
// File pointer: fptr 
// Traverses the tree in post order fashion and
// save the ascii value of the node if the node is a leaf node
// else saves 0 (zero)
// The file is a binary file so use the appropriate function to write to the file 
void saveBST(TreeNode* node, FILE* fptr)
{
	// TODO: Complete this method	
}

#endif


#ifndef TEST_CLEANUP
// Deallocates the memory for the entire tree
void cleanup(TreeNode* root)
{
	// TODO: Complete this method
}

#endif

#ifndef TEST_MAIN
// The arguments passed in from the command line are:
// argv[1] the random seed to initialize the array generator
// argv[2] the length of the array
// argv[3] the output file name
// Note the first two arguments are of long int type so use strtol rather than atoi
int main(int argc, char** argv)
{
	// TODO: Complete this method
	// Check if the number of arguments are correct
	// If so use strtol to convert argv[1] and argv[2] to long int

	// Create an array
	// use the converted argv[1] and argv[2] values to call the
	// CreateArrayOfElements(long randomSeed, long len)

	// Build the BST from the array

	// Perform post order traversal while saving the elements as described in the readme

	// Cleanup allocated variables and trees

}

#endif
