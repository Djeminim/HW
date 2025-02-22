//Выведите все числа от A до B включительно, в порядке возрастания, 
//если A < B, или в порядке убывания в противном случае.
#include <stdio.h>

void queue(int n, int m)
{
	
	if (n==0 && m==0)
	printf("%i", 0);
	
	else if (n<m)
	{
		printf("%i ", n);
		n++;
		queue(n,m);
		
	}
	
	else if (n>m)
	{
		printf("%i ", n);
		n--;
		queue(n,m);
	}
	
	else if (m==n)
	printf("%i ", m);
	
}


int main()
{
	int n,m;
	scanf("%i%i", &n,&m);
    queue(n,m);
    
    
	
    return 0;
}
 


