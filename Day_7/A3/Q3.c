// Write the program tail, which prints the last n lines of its input.
// By default, n is 10, let us say, but it can be changed by an optional argument,
// so that tail -n that prints the last n lines of the input.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define default_lines 10
#define lines   1024
#define lengthofline  100


int main(int argc, char const *argv[])
{
	int nlines = default_lines; //default
	char line[lengthofline]; 	//length of the line
	                          
//--------------------------------------------------------------------------------

	printf("Enter the number of lines for Scannig..\n");
	int temp;
	scanf("%d",&temp);
	while (nlines>temp && lines < temp)
	{
		printf("Enter the valid number of lines.Default lines is 10.\nEnter 10 or more than 10 and less than 100.\n");
		scanf("%d",&temp);
	}
	nlines = temp;

//-------------------------------------------------------------------------------

	printf("Enter the number of lines for printing\n");
	scanf("%d",&temp);
	while (temp > nlines || temp < 0 || temp > lines)
	{
		printf("Enter the valid number of lines.Total available lines are %d\nEnter less than or equal to %d\n",nlines,nlines);
		scanf("%d",&temp);
	}
	int print_nlines = temp;

	char *lines_array[nlines]; 	//store the pointers of each line
//---------------------------------------------------------------------------------
	printf("Enter the input for Scannig...\n");
	// lines_array = (char*)malloc(nlines*sizeof(char)); //lines
	for (int i = 0; i < nlines+1; i++) {
		char *ptr = (char*)malloc(lines *sizeof(char)); //each line memory
		if (ptr == NULL) { 
        	printf("Memory not allocated.\n"); 
        	exit(0); 
    	}
		gets(line);
		strcpy(ptr, line);
		// printf("%s\n", ptr);
		lines_array[i] = ptr;
		// printf("%s\n",lines_array[i]);
	}
	printf("-----------output below--------------\n");
	for (int i = nlines-print_nlines+1; i <= nlines; i++) {
		printf("%s\n", lines_array[i]);
	}
	return 0;

}