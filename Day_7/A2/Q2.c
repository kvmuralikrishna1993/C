// Write versions of the library functions 
// strncpy, strncat, and strncmp; 
// which operate on at most the first n characters of their argument strings.
// strncpy (s, t, n) copies at most n characters of t to s.
// strncat(s, t, n) appends at most n characters of t to s.
// strncmp(s, t, n) compares at most n characters of s and t.
// Returns 0 if at most n characters are equal, 1 otherwise.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* stringcopy (char s[], char t[], int n);
char* stringcat (char s[], char t[], int n);
int stringcmp (char s[], char t[], int n);
static char error[] = "Index out of Bound";

int main(int argc, char const *argv[])
{
	char s[] = "abcdc";
	char t[] = "xyz";
	char k[] = "abc";
	//un comment the test cases
	// printf("%s\n",stringcopy(s,t,3));
	// printf("%s\n",stringcopy(s,t,4));
	printf("%s\n", stringcat(s,t,3));
	// printf("\n\n%d\n", stringcmp(s,t,3));
	// printf("%d\n", stringcmp(s,k,3));

}

char* stringcopy(char s[], char t[], int n) {
	
	if (n > strlen(s) || n > strlen(t))
	{
		return error;
	}else{
		for (int i = 0; i < n; i++)
		{
			s[i] = t[i];
		}
		return s;
	}
}
char* stringcat (char s[], char t[], int n){
	int size = strlen(s)+n;
	char str[size]; 
	for (int i = 0; i < strlen(s); i++){
		str[i] = s[i];
	}
	int j = strlen(s);
	if (n > strlen(t)) {
		return error;
	}
	for (int i = 0; i < n; i++){
		str[j] = t[i];
		j++;

	}
	str[j] = '\0'; //end the character
	return str;

}
int stringcmp (char s[], char t[], int n){
	if(n > strlen(s) || n > strlen(t) ){
		return -1;
	} else {
		for (int i = 0; i < n; ++i)
		{
			// printf("%c %c\n", s[i], t[i]);
			if(s[i] != t[i]) {
				return 1; 
			}
		}
		return 0;
	}

}
