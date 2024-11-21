
//Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.  
#include <stdio.h>



void binar_system(int num)
{
	static int i=0;
	int a;
	
	
	if (num>=1)
	{	
		a=num%2;
		num=num/2;
		if (a==1)
		i++;
		binar_system(num);		
	}
	else if(num<1)
	printf("%i", i) ;

}


int main()
{	
	
	int num;
	scanf ("%i", &num);
    binar_system(num);
    
    return 0;
}
 



