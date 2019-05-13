// Write the c function strrindex (s, t), 
// which returns the position of the rightmost occurrence of t in s, or - 1 
// if there is none. Test your function against the test cases.
// Build your own test cases.
#include <stdio.h>
#include <string.h>
int strrindex(char str[], char ch);

int main(int argc, char const *argv[])
{
	char str[] = "magical language";
	printf("%d\n", strrindex(str,'u'));
	return 0;
}

int strrindex(char str[], char ch) {
	for (int i = strlen(str); i >= 0; i--) {
		if(str[i] == ch) {
			return i;
		}
	}
	return -1;
}