#include <stdio.h>
#include <string.h>
#include "strprop.h"

int main()
{
	static char a[4] = "abcd";
	char* b;
	b = strrev(a);
	// printf("%d\n",b);
	return 0;
}