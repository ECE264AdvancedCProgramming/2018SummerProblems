#include "pa05.h"
#include <stdlib.h>
#include <ctype.h>

// sort the array depending on the compare function
void sort(compare_fptr compare, Node* std_list)
{
	b_sort(std_list, compare);
}

/* function to swap data of two nodes a and b*/
void swap(Node *a, Node *b)
{
    Student* temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void b_sort(Node* head, compare_fptr compare)
{
	int swapped;
	Node* p;
	Node* lptr = NULL;

	/* Checking for empty list */
	if (head == NULL)
	{
		return;
	}

	do
	{
		swapped = 0;
		p = head;

		while (p->next != lptr)
		{
		    if (compare(p->data, p->next->data) > 0)
		    { 
			swap(p, p->next);
			swapped = 1;
		    }

		    p = p->next;
		}

		lptr = p;
	}
	while (swapped);
}


bool isNumber(char* string)
{
	bool is_num = true;
	for(int i = 0; i < strlen(string); i++)
	{
		if(isdigit(string[i]) == 0)
		{
			is_num = false;
			break;
		}
	}

	return is_num;
}

void cleanup_and_exit(Parse* p)
{
	printf("Unknown format\n");
	free(p->select);
	free(p);
	exit(EXIT_FAILURE);
}

void parse_sort(char** argv, Parse* p)
{
		if(strcmp("SORT_BY", argv[1]) != 0)
		{
			cleanup_and_exit(p);
		}

		if(strcmp("ID", argv[2]) == 0)
		{
			p->compare = compare_id;
		}
		else if(strcmp("NAME", argv[2]) == 0)
		{
			p->compare = compare_name;
		}
		else if(strcmp("YEAR", argv[2]) == 0)
		{
			p->compare = compare_year;			
		}
		else
		{
			cleanup_and_exit(p);
		}
}


void parse_sel(char** argv, Parse* p, int i)
{
		if(strcmp("WHERE", argv[i]) != 0)
		{
			cleanup_and_exit(p);
		}

		if(strcmp("ID", argv[i+1]) == 0)
		{
			p->select->sel_func = select_id;
			if(isNumber(argv[i+3]))
			{
				int* val = malloc(sizeof(int));
				*val = atoi(argv[i+3]);
				p->select->value = (void*)val;
			}
			else
			{
				cleanup_and_exit(p);
			}

		}
		else if(strcmp("NAME", argv[i+1]) == 0)
		{
			p->select->sel_func = select_name;
			char* val = malloc(strlen(argv[i+3]) + 1);
			strcpy(val, argv[i+3]);
			p->select->value = (void*)val;				
		}
		else if(strcmp("YEAR", argv[i+1]) == 0)
		{
			p->select->sel_func = select_year;
			if(isNumber(argv[i+3]))
			{
				int* val = malloc(sizeof(int));
				*val = atoi(argv[i+3]);
				p->select->value = (void*)val;
			}
			else
			{
				cleanup_and_exit(p);
			}			
		}
		else
		{
			cleanup_and_exit(p);
		}

		if(strcmp(">", argv[i+2]) == 0)
		{
			p->select->greater = true;
		}
		else if(strcmp("<", argv[i+2]) == 0)
		{
			p->select->greater = false;			
		}
		else
		{
			cleanup_and_exit(p);
		}
}


// Takes the input arguments and allocates memory for Parse obj, and initializes 
// the values depending on the arguments 
Parse* parse(int argc, char ** argv)
{
	Parse* p = malloc(sizeof(Parse));
	p->select = malloc(sizeof(Select));
	p->select->sel_func = select_all;
	p->compare = no_compare;
	argc = argc - 1;
	if(argc == 2)
	{
		parse_sort(argv, p);
	}
	else if(argc == 4)
	{
		parse_sel(argv, p, 1);
	}
	else if(argc == 6)
	{
		parse_sort(argv, p);
		parse_sel(argv, p, 3);
	}
	else
	{
		cleanup_and_exit(p);
	}

	return p;	
}

void cleanup_parse_obj(Parse* parse_obj)
{
	free(parse_obj->select->value);
	free(parse_obj->select);
	free(parse_obj);
}

void print_list(Node* p)
{
	while(p != NULL)
	{
		if(p->selected)
		{
			printf("%d: %s , 20%d\n", p->data->id, p->data->name, p->data->year);
		}

		p = p->next;
	}
}

int no_compare(const void* a, const void* b)
{
	return 0;
}
