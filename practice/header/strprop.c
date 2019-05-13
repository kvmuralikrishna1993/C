#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char input_rev[1000];
static char input_low[1000];
static char input_hig[1000];
//reverse the string
char* strrev(char input[]) {
	int j = 0;
	int s = strlen(input);
	
	for (int i = strlen(input)-1; i >= 0; i--) {
		input_rev[j] = input[i];
	}

	return (char*)input_rev;
}
//lower case
char* strlow(char input[]) {
	int j = 0;
	
	for (int i = strlen(input)-1; i >= 0; i--){
		input_low[j] = tolower(input[i]);
	}
	return (char*)input_low;
}

//higher case
char* strhig(char input[]) {
	int j = 0;
	
	for (int i = strlen(input)-1; i >= 0; i--) {
		input_hig[j] = toupper(input[i]);
	}
	return (char*)input_hig;
}