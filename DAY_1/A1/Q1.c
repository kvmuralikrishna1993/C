// Question: Write a program to copy its input to its output,
// replacing each string of one or more blanks by a single blank
// 
//Program below:
//==============
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char input[1000];
    int i=0;
    gets(input); //taking input including spaces

    while(input[i]!='\0'){ //check upto end of the msg --> default end is \0

        if(input[i]!=' ' || input[i+1]!=' ') {
        	//print untill we got double spaces and escape the double space
        	printf("%c",input[i]);
        }
        i++;
    }
    printf("\n");

	return 0;
}