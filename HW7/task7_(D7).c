//Составить рекурсивную функцию, печать всех чисел от N до 1
#include <stdio.h>

void queue(int n)
{
	
	if (n>0)
	{	
		printf("%i ", n);
		n=n-1;		
		queue(n);
			
	}
	
	
}


int main()
{
	int n;
	scanf("%i", &n);
    queue(n);
    
    if (n==0)
	printf("%i", 0);
	
    return 0;
}
 


