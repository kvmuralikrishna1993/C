#include <stdio.h>
int main() {
char name[10];
char  a[] = "adasasds"; //no length provided
char c[5] = "abcde"; // equal to length of string
// char b[5] = "dsfsfds"; //more than length of string --> error
// int age;
// printf("Enter your first name and age: \n");
// scanf("%s %d", name, &age);  //reading the input
// printf("You entered: %s %d \n",name, age);
//scanf function is that it never reads an entire string.
//It will halt the reading process as soon as whitespace
//form feed, vertical tab, newline or a carriage return occurs

//---------------------------------------
char full_name[25];
printf("Enter your full name:  \n");
gets(full_name);
printf("My full name is %s  \n",full_name);
//In order to read a string contains spaces, we use the gets() function.
//Gets ignores the whitespaces.
//It stops reading when a newline is reached (the Enter key is pressed).
//-----------------------------------------------------
char name1[10];
printf("Enter your  name plz:  \n");
fgets(name1, 10, stdin);
printf("My name is %s  \n",name1);
//Another safer alternative to gets() is fgets() function which reads a specified number of characters.

//printing a string
// printf("%s \n", name1);

//fputs
// char town[40];
// printf("Enter your town: ");
// gets(town);
// fputs(town, stdout);

//puts
char name2[15];
gets(name2);        //reads a string
puts(name2);		////displays a string

}
