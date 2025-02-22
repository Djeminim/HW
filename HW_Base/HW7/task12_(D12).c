
//Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.  
#include <stdio.h>


void natur(int num)
{
	static int a=0,b=1;
		
	for(int i=0;i<b;i++)
	{
		if (a<num)
		printf("%i ", b);
		a++;		
	}
	b++;
	if(a<num)
	natur(num);	
}	




int main()
{		
	int num;
	scanf ("%i", &num);
    natur (num);
    
    return 0;
}
 



