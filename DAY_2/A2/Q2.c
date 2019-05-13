// Question: Write the function htoi (s), which converts a string of hexadecimal digits
// (including an optional Ox or ox) into its equivalent integer value.
// The allowable digits are 0 through 9, a through f, and A through F
#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char value[]); //returns int value
int getvalue(char each); //return each char value

int main(int argc, char const *argv[]) {
	char hexa[] = "0x7DE";
	int intValue = htoi(hexa);
	printf("%d\n",intValue);
	return 0;
}

int htoi(char hexa[]) {
	int j = 0;
	int sum = 0;
	for (int i = strlen(hexa)-1; i >= 0; i--){
		sum = sum + getvalue(hexa[i])*pow(16,j);
		j++;
	}
	return sum;
}

int getvalue(char each) {
	int num=0;
    if(each>='0' && each<='9')
    {
        num=each-0x30;
        // printf("%d\n",0x30);
        // printf("%d\n",num);
    }
    else
    {
        switch(each)
        {
            case 'A': case 'a': num=10; break;
            case 'B': case 'b': num=11; break;
            case 'C': case 'c': num=12; break;
            case 'D': case 'd': num=13; break;
            case 'E': case 'e': num=14; break;
            case 'F': case 'f': num=15; break;
            default: num=0;
        }
    }
    return num;
}