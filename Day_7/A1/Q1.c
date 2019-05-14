// Write the c function strrindex (s, t), 
// Write the function strend (s ,t ),
// which returns 1 if the string t occurs at the end of the string s,
// and zero otherwise. 
// Write the test cases and check your code against
// the test cases that you have defined.

#include <stdio.h>
#include <string.h>
int strend(char str[], char ch);

int main(int argc, char const *argv[])
{
	char str[] = "magical language";
	printf("%d\n", strend(str,'u'));
	printf("%d\n", strend(str,'e'));
	return 0;
}

int strend(char str[], char ch) {
	if (str[strlen(str)-1] == ch)
	{
		return 1;
	} else {
		return 0;
	}
}