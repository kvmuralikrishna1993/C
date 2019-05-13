// Question: Write a program to determine the ranges
// (Min value and Max value) of char, int, long, float and double.
// Hint: limits.h and float.h
// (Try for various constants for float and observe the output).
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	printf("Min char: %d\n", (unsigned char) ~0 >> 1);
	printf("Max char: %d\n", -((unsigned char) ~0 >> 1)-1);
	printf("Min Int: %d\n", (unsigned int) ~0 >> 1);
	printf("Max int: %d\n", -((unsigned int) ~0 >> 1)-1);
	printf("Min Long: %ld\n", LONG_MIN);
	printf("Max Long: %ld\n", LONG_MAX);
    printf("Min Float: %e\n", FLT_MIN);
    printf("Max Float: %e\n", FLT_MAX);
    printf("Min Double: %e\n", DBL_MIN);
    printf("Max Double: %e\n", DBL_MAX);
	return 0;
}