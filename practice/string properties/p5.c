#include <stdio.h>
#include <string.h> //string library
#include <ctype.h>
int main () {
//string initialization
char string1[15]="Hello";
char string4[15]="Hello";
char string2[15]=" World!";
char string3[15];
int val;

//string comparison
val= strcmp(string1,string2); //for false
printf("%d\n", val);
if(val == 0){
    printf("Strings are equal\n");
}
else{
    printf("Strings are not equal\n");
}

val= strcmp(string1,string4); //true ==> returns 0 (equal strings)
printf("%d\n", val);

//string concatenation
printf("Concatenated string:%s",strcat(string1,string2)); //string1 contains hello world!

//string length
printf("\nLength of first string:%lu",strlen(string1));
printf("\nLength of second string:%lu",strlen(string2));

//string copy
printf("\nCopied string is:%s\n",strcpy(string3,string1));  //string1 is copied into string3

// printf("\nLength of first string:%s",tolower(string1)); //lower case --> nor work || belongs microsoft c library
// printf("\nLength of second string:%s",strupr(string2)); //upper case
// printf("\nLength of first string:%s",strrev(string1)); //reverse
// printf("\nLength of second string:%lu",strlen(strrev(string2))); //length of reverse


return 0;
}

//i am happy ==> str1
//i am happie ==> str2
//
//when we compare (str1,str2)
//str1 --> y > str2 --> i ==> hence returns positive
//if it is low then it will return negative value



// %c	Character ==>	char,unsigned char
// %d	Signed Integer  ==>	short,unsigned short, int, long
// %e or %E	Scientific notation of float values	 ==>	float ,double
// %f	Floating point	 ==>	float
// %g or %G	Similar as %e or %E	 ==>	float,double
// %hi	Signed Integer(Short)	 ==>	short
// %hu	Unsigned Integer(Short)	 ==>	unsigned short
// %i	Signed Integer	 ==>	short ,unsigned short,int,long
// %l or %ld or %li	Signed Integer	 ==>	long
// %lf	Floating point	 ==>	double
// %Lf	Floating point ==>		long double
// %lu	Unsigned integer	 ==>	unsigned int,unsigned long
// %lli, %lld	Signed Integer	 ==>	long long
// %llu	Unsigned Integer	 ==>	unsigned long long
// %o	Octal representation of Integer. ==>		short,unsigned short,int,unsigned int,long
// %p	Address of pointer to void void *  ==>		void *
// %s	String	 ==>	char *
// %u	Unsigned Integer	 ==>	unsigned int,unsigned long
// %x or %X	Hexadecimal representation of Unsigned Integer	 ==>	short,unsigned short,int,unsigned int,long
// %n	Prints  ==>	 nothing	
// %%	Prints  ==>	% character