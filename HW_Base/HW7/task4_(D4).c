//Выведите все его цифры по одной, в прямом порядке
#include <stdio.h>

void print_num(int num)
{
	int b;
	
	if (num==0)
	printf ("%i", 0);
	
	if (num > 0)
	{	
		b = num % 10;
		num = num / 10;
		
		print_num(num);
		printf ("%i ", b);		
	}
}

int main()
{
	
	int num;
	scanf ("%i", &num);
    print_num(num);
    return 0;
}
 


