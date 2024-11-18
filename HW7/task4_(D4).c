//Выведите все его цифры по одной, в прямом порядке
#include <stdio.h>

void print_num(void)
{
	int c;
	if ((c=getchar()) != '\n')
	print_num();
	if (c != '\n')
	putchar(c);
}
int main()
{
	
    print_num();
    return 0;
}
 



