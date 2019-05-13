// Refer to the C function atof that converts string to float.
//Extend atof to handle scientific notation of the form 123.45e-6
//where a floating-point number may be followed by e or E
//and an optionally signed exponent.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_e(char str[]);
int getpower(char str[]);
int main(int argc, char const *argv[])
{
	char str[] = " -2309.12E-15";
	float value;
	if(check_e(str)) {

	} else {
		printf("%e\n", atof(str));
	}
	return 0;
}

int check_e(char str[]) {
	for (int i = strlen(str)-1; i >=0 ; i--) {
		if(str[i] == 'e') {
			return 1;
		} else if(str[i] == 'E') {
			return 1;
		}
	}return 0;
}

int getpower(char str[]) {
	for (int i = strlen(str)-1; i >=0 ; i--) {
		if(str[i] == '-') {
			break;
		}

	}
	return 0;
}