#include<stdio.h>	//Pre-processor directive
int main(void)		//main function declaration
{
printf("Hello World\n");	//to output the string on a display
// getch ();		//terminating function
}

//in one command ==> gcc -Wall hello.c -o file1 && ./file1
//-o represents output after that name of output file given --> above file1 is the name
//-Wall enables all compiler’s warning messages
//./file ==> executing file1 that is generated from hello.c after compilingw
//		(preprocessing)		(compiling) 	(assembly)		(Linking)
//.c 		==> 		.i  	==> 	.s  	==> 	.o   	==> 	exe