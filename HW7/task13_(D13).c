
//Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.  
#include <stdio.h>


void natur_div(int num)
{
	static int b=2;
	
	if (num>1)
	{
		if(num%b==0 )
		{
			num=num/b;	
			printf("%i ", b);	
			
		}
			if(num%b!=0)
			b++;
			
			natur_div(num);		
		}
	
}	




int main()
{		
	int num;
	scanf ("%i", &num);
    natur_div (num);
  
    return 0;
}
 



