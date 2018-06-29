#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_lines(FILE* fptr)
{
	int lines = 0;
	while (!feof(fptr))
	{
		char ch = fgetc(fptr);
		if (ch == '\n')
		{
			lines++;
		}
	}

	fseek(fptr, 0, SEEK_SET);

	return lines;
}

char** create_string_array(FILE* fptr, int lines)
{
	char * * file = malloc(sizeof(char*)* lines);

	int i = 0;
	char line[512];
	while (fgets(line, sizeof(line), fptr))
	{
        	char* line_array = malloc((strlen(line) + 1) * sizeof(char));
		strcpy(line_array, line);
		file[i++] = line_array; 
    	}

	fseek(fptr, 0, SEEK_SET);
	return file;
}

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

	int lines_file1 = count_lines(fptr1);
	int lines_file2 = count_lines(fptr2);

	if(lines_file1 != lines_file2)
	{
		pass = false;
	}

	char** file1 = create_string_array(fptr1, lines_file1);
	char** file2 = create_string_array(fptr2, lines_file2);

	for(int i = 0; i < lines_file1; i++)
	{
		if(strlen(file1[i]) != strlen(file2[i]))
		{
			pass = false;
			break;
		}
 
		if(strcmp(file1[i], file2[i]) != 0)
		{
			if(strcmp(file1[lines_file1 - i - 1], file2[i]) != 0)
			{
				pass = false;
				break;
			}
		}
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
