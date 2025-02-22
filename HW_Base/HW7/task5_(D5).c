
//Перевести натуральное число в двоичную систему счисления. 
#include <stdio.h>

void binar_system(int num)
{
	int a;
	
	if(num==0) 
	printf("%i", 0);
	
	if (num>=1)
	{	
		a=num%2;
		num=num/2;
		binar_system(num);
		printf("%i", a);
	}
}


int main()
{
	
	int num;
	scanf ("%i", &num);
    binar_system(num);
    return 0;
}
 



