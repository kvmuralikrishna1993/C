#include <stdio.h>
int main()
{
	// a void pointer is also called as a generic pointer
void *p = NULL; 	//void pointer
printf("The size of pointer is:%lu\n",sizeof(p));
printf("%p\n",p);
// printf("%d\n",*p); //--> error

int *q; 	//wild pointer
printf("\n%p",q);
// printf("\n%p",*q);

return 0;
}