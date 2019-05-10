//Question: Write a function reverse (s) that reverses the character string s
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
	char input[1000];
	char input_rev[strlen(input)];
	char input_low[strlen(input)];
	char input_hig[strlen(input)]; 
	gets(input);

	int j = 0;
	//reverse the string
	for (int i = strlen(input)-1; i >= 0; i--)
	{
		input_rev[j] = input[i];
		j++;
	}
	printf("reverse_string:  %s\n",input_rev);

	//lower case
	j = 0;
	for (int i = 0; i <= strlen(input)-1; i++)
	{
		input_low[j] = tolower(input[i]);
		j++;
	}
	printf("lowercase_string:  %s\n",input_low);

	//higher case
	j = 0;
	for (int i = 0; i <= strlen(input)-1; i++)
	{
		input_hig[j] = toupper(input[i]);
		j++;
	}
	printf("highercase_string:  %s\n",input_hig);

	return 0;
}