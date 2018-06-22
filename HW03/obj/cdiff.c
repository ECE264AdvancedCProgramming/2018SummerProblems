#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define EPSILON 1e-4

int main(int argc, char * * argv)
{
	bool pass = true;
	if(argc != 3)
	{
		return EXIT_FAILURE;
	}

	FILE* fptr1;
	FILE* fptr2;

	fptr1 = fopen(argv[1], "r");
	if(fptr1 == NULL)
	{
		printf("File does not exist on disk\n");
		return EXIT_FAILURE;
	}

	fptr2 = fopen(argv[2], "r");
	if(fptr2 == NULL)
	{
		fclose(fptr1);
		printf("File does not exist on disk\n");
		return EXIT_FAILURE;
	}
	
	double exp, act;
	int in1ok = fscanf(fptr1, "%lf", &exp);
	int in2ok = fscanf(fptr2, "%lf", &act);
	while(in1ok == 1 && in2ok == 1)
	{
		if(exp - act > EPSILON)
		{
			pass = false;
			break;
		}

		in1ok = fscanf(fptr1, "%lf", &exp);
		in2ok = fscanf(fptr2, "%lf", &act);
	}

	if(in1ok != in2ok)
	{
		pass = false;
	}

	fclose(fptr1);
	fclose(fptr2);

	if(pass)
	{
		printf("Test case passed\n");
	}
	else
	{
		printf("Test case failed\n");
	}

	return EXIT_SUCCESS;
}
