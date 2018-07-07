#include "pa05.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
	// Call parse and store the return value in some variable
    	// parse is a function given to you. See pa05.h

	// Build a list from the text file,
	// Call build_list, filename is "database.txt"


	// Next select all the the nodes based on condition

	// Call the sort function to sort the list 
    	// Note this function is already provided to you, see pa05.h

	// Call print list
    	// You may use the provided function

	// Destroy the list


	// Call cleanup_parse_obj(Parse* parse_obj)
    	// Note this function is already provided to you, see pa05.h
	return EXIT_SUCCESS;
}

// This function is of the "compare_fptr" function pointer
// Will be assigned to the Parse->compare by the parse function if the sort is done by id
// Return value meaning
// < 0 The element pointed by 'a' goes before the element pointed by 'b'
// 0  The element pointed by 'a' is equivalent to the element pointed by 'b'
// > 0 The element pointed by 'a' goes after the element pointed by 'b'
// Note do not modify compare_id this is for your reference
int compare_id(const void* a, const void* b)
{
	// By default the pointers are const void* cast them to the right type
	Student* std_a = (Student*)a;
	Student* std_b = (Student*)b;

	return std_a->id - std_b->id;
}


#ifndef TEST_COMPARE_YEAR
// This function is of the "compare_fptr" function pointer
// Will be assigned to the Parse->compare by the parse function if the sort is done by year
// Return value meaning
// < 0 The element pointed by 'a' goes before the element pointed by 'b'
// 0  The element pointed by 'a' is equivalent to the element pointed by 'b'
// > 0 The element pointed by 'a' goes after the element pointed by 'b'
int compare_year(const void* a, const void* b)
{
	// Complete this function similar to compare_id
	return 0; // Dummy feel free to rewrite this function completely
}

#endif

#ifndef TEST_COMPARE_NAME
// This is a function whose type matches that of the "compare_fptr" function pointer
// Will be assigned to the Parse->compare by the parse function if the sort is done by name
// Return value meaning
// < 0 The element pointed by 'a' goes before the element pointed by 'b'
// 0  The element pointed by 'a' is equivalent to the element pointed by 'b'
// > 0 The element pointed by 'a' goes after the element pointed by 'b'
int compare_name(const void* a, const void* b)
{
	// Complete this function similar to compare_id
	// Hint: strcmp
	return 0; // Dummy feel free to rewrite this function completely
}

#endif

// This is a function whose type matches that of the "sel_func" function pointer
// Will be assigned to the Parse->selecrt->sel_func by the parse function if the selection is to be by id
// Inputs, Student* node: the node which needs to be selcted by the select process or not
// value, holds the value to be compared ex. if the command was WHERE ">" 25, value is 25 
// greater is true is the command was ">" else greater is false when the command is "<"
// Return value meaning
// If the node satisfies the condition then return true i.e select the node
// else not to be selected
// Note do not modify select_id this is for your reference
bool select_id(Student* node, const void* value, bool greater)
{
	int comp_val = *(int*) value;
	bool select = true;
	if(node->id > comp_val)
		select = true;
	else
		select = false;

	if(!greater)
		select = !select;

	return select;
}


#ifndef TEST_SEL_YEAR
// This is a function whose type matches that of the "sel_func" function pointer
// Will be assigned to the Parse->selecrt->sel_func by the parse function if the selection is to be by year
// Inputs, Student* node: the node which needs to be selcted by the select process or not
// value, holds the value to be compared ex. if the command was WHERE ">" 25, value is 25 
// greater is true is the command was ">" else greater is false when the command is "<"
// Return value meaning
// If the node satisfies the condition then return true i.e select the node
// else not to be selected
bool select_year(Student* node, const void* value, bool greater)
{
	// Complete this function similar to select_id
	return true; // Dummy feel free to rewrite this function completely
}

#endif

#ifndef TEST_SEL_NAME
// This is a function whose type matches that of the "sel_func" function pointer
// Will be assigned to the Parse->selecrt->sel_func by the parse function if the selection is to be by name
// Inputs, Student* node: the node which needs to be selcted by the select process or not
// value, holds the value to be compared ex. if the command was "WHERE ">" Damian", value is Damain 
// greater is true is the command was ">" else greater is false when the command is "<"
// Return value meaning
// If the node satisfies the condition then return true i.e select the node
// else not to be selected
bool select_name(Student* node, const void* value, bool greater)
{
	// Complete this function similar to select_id
	// Hint: strcmp
	return true; // Dummy feel free to rewrite this function completely
}

#endif

// This is a function whose type matches that of the "sel_func" function pointer
// Will be assigned to the Parse->selecrt->sel_func by the parse function if the selection is to be by name
// Inputs, Student* node: the node which needs to be selcted by the select process or not
// value, holds the value to be compared ex. if the command was "WHERE ">" Damian", value is Damain 
// greater is true is the command was ">" else greater is false when the command is "<"
// Return is always true i.e all nodes are selected
bool select_all(Student* node, const void* value, bool greater)
{	
	return true;
}

#ifndef TEST_BUILD_LIST
// This function reads the file whose name is given by the "filename"
// Returns the head of the (Node*) Linked List whose nodes point to a student structure
// See the definition of Node in "pa05.h"
// The linked list is list of the entire database 
Node* build_list(char* filename)
{
	// Read from the file "filename"
	// Create a list of Node*
	// Return head of the list

	// Tips: Its probably useful to break this function down into smaller functions
	return NULL; // Dummy feel free to rewrite this function completely
}

#endif


#ifndef TEST_DEST_LIST
void destroy_list(Node* h)
{
	// Make sure to free the list correctly
	// Keep in mind to do the following
	// Free node->data->name
	// Free node->data
	// Free node
}

#endif


#ifndef TEST_SELECT
Node* select_phase(Select* select, Node* std_list)
{
	// Node has a selected bool
	// Set the bool to true if select->sel_func returns true
	// else two choices
	// 1)delete that node from the list
	// 2) or while printing only print the selected nodes
	// if you choose option 2 you will need to write your own print list method
	return NULL; // Dummy feel free to rewrite this function completely
}

#endif


