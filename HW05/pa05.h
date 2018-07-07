#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef int (*compare_fptr)(const void*,const void*);

// Student structure
typedef struct
{
	int id;
	char* name;
	int year;
} Student;

// Node definition for the list of students
typedef struct listnode
{
	struct listnode* next;
	Student* data;
	bool selected;
} Node;

// Function pointer returns wheather the node from the list needs to be added into the list or not 
typedef bool (*select_func)(Student*, const void*, bool);

// The "Select" struct stores the information needed by the selection phase 
typedef struct
{
	select_func sel_func;
	bool greater;
	void* value;
} Select;

// Parse struct, this stores the information in an easy to process format
// The parse function initializes an return an object of this structure
typedef struct
{
	// The compare is a function pointer used by the sorting phase
	compare_fptr compare;

	// The "Select" struct stores the information needed by the selection phase
	Select*	select;
} Parse;

int no_compare(const void* a, const void* b);

int compare_id(const void* a, const void* b);

int compare_year(const void* a, const void* b);

int compare_name(const void* a, const void* b);

bool select_id(Student* node, const void* value, bool greater);

bool select_year(Student* node, const void* value, bool greater);

bool select_name(Student* node, const void* value, bool greater);

bool select_all(Student* node, const void* value, bool greater);

void sort(compare_fptr compare, Node* std_list);

void swap(Node *a, Node *b);

void b_sort(Node* head, compare_fptr compare);

Parse* parse(int argc, char ** argv);

void print_list(Node* p);

void cleanup_parse_obj(Parse* parse_obj);

int no_compare(const void* a, const void* b);

Node* build_list(char* filename);

Node* select_phase(Select* select, Node* std_list);

void destroy_list(Node* h);
	
