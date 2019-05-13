#include <stdio.h>
#include <string.h>
#include "strprop.h"

int main()
{
	static char a[4] = "abcd";
	char* b;
	b = strrev(a);
	printf("%s\n",(char*)&b);
	return 0;
}