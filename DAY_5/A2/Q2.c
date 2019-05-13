// Refer to the C function atof that converts string to float.
//Extend atof to handle scientific notation of the form 123.45e-6
//where a floating-point number may be followed by e or E
//and an optionally signed exponent.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int check_e(char str[]);
int getpower(char str[]);
int getindex_e(char str[]);
float getvalue(char str[]);

int main(int argc, char const *argv[])
{
	char str[] = "-2309.12E-15";
	float value;
	if(check_e(str)) {
		printf("%lf\n", (getvalue(str)*pow(10,getpower(str))));
		// int power = getpower(str);
		// float value = getvalue(str);
		// float realvalue = value * pow(10,power);
		// printf("%lf\n", realvalue);
		//output: -2309120117187500032.000000
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
	int index = getindex_e(str);
	int size = strlen(str) - (index+2);
	char power[size];
	int j = 0;
	for (int i = index+2; i < strlen(str) ; i++) {
		power[j] = str[i];
		j++;
	}
	return atoi(power);
}

int getindex_e(char str[]) {
	for (int i = strlen(str); i >= 0; i--) {
		if(str[i] == 'E' || str[i] == 'e') {
			return i;
		}
	}
	return -1;
}

float getvalue(char str[]){
	int index = getindex_e(str);
	char value[index];
	int j = 0;
	for (int i = 0; i < index; i++) {
		value[j] = str[i];
		j++;
	}
	return atof(value);
}

