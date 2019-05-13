#include <stdio.h>
#include <string.h>
#include "strprop.h"

int main()
{
	char a[4] = "abcd";
	char b;
	b = strrev(a);
	printf("%s\n",b);
	return 0;
}