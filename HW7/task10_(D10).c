//Программа должна вывести слово YES, если число простое или NO в противном случа
#include <stdio.h>

int is_prime(int n)
{
	static int i=1,c=0;
	
	if (i<=n)
	{	
		if(n%i==0)	c++;
		
		i++;
		is_prime(n);		
	}
	
	else if (c>=3 || n==0 || n==1)
	{
		printf("NO");			
	}
	
	else 
	{
		printf("YES");						
	}
	
	return 0;
	
}


int main()
{
	int n;
	scanf("%i", &n);
    is_prime(n);
    
    
	
    return 0;
}
 


