//Напечатать строку наоборот.
#include <stdio.h>

void revers(void)
{
	char c;
	if((c=getchar()) != '.')
	revers();
	if (c != '.')
	putchar(c);
	
}


int main()
{
    revers();
    return 0;
}
 


