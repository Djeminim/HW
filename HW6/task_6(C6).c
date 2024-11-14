#include <stdio.h>
#include <math.h>


int main()
{
	unsigned long long  sum=1;
	int a;
	
	scanf("%i", &a);
	
	for(int i=1;i<=a;i++)
	{
		sum= pow(2,(i-1));
	}
	
	printf("%llu ", sum);
	    
    return 0;
}

