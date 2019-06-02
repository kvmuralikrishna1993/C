#include <stdio.h>
int main(int argc, char const *argv[])
{
 	int a  = 10;
 	int* p = &a; //p is a --> address
 	             
 	//ampersant returns address fo variable
 	//* declaring the pointer
 	//* returns the value inside of that pointer
 	//here p has address of a ; to print is  we use p;
 	//what about values that contained inside the that address
 	//use *p or a ==> here * returns the value inside that addresss
 	 
 	int** q = &p;	//q is p --> address
 	printf("%d\n", a);
 	printf("%p\n", p); //returns address #pointer reference
 	printf("%d\n", *p); //returns the value inside that address #pointer dereference
 	printf("%p\n", q); //returns the address of that pointer. 
	return 0;
}