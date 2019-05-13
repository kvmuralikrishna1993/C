#include <stdio.h>
#include <string.h>
#include <ctype.h>

//reverse the string
char* strrev(char input[]) {
	int j = 0;
	int s = strlen(input);
	char input_rev[s];
	for (int i = strlen(input)-1; i >= 0; i--) {
		input_rev[j] = input[i];
	}
	return &input_rev;
}
//lower case
char* strlow(char input[]) {
	int j = 0;
	char input_low[strlen(input)];
	for (int i = strlen(input)-1; i >= 0; i--){
		input_low[j] = tolower(input[i]);
	}
	return input_low;
}

//higher case
char* strhig(char input[]) {
	int j = 0;
	char input_hig[strlen(input)];
	for (int i = strlen(input)-1; i >= 0; i--) {
		input_hig[j] = toupper(input[i]);
	}
	return input_hig;
}