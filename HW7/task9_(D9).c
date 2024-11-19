//Выведите все числа от A до B включительно, в порядке возрастания, 
//если A < B, или в порядке убывания в противном случае.
#include <stdio.h>

int sum_digits(int n)
{
	static int c=0;
	int i;
	
	if (n>=0)
	{
		i=n%10;
		n=n/10;
		c=c+i;
		printf("%i", c);
		sum_digits(n);
		
	}
	
	return c;
	

}


int main()
{
	int n;
	scanf("%i", &n);
    sum_digits(n);
    
    
	
    return 0;
}
 


