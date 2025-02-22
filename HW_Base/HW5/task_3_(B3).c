
#include <stdio.h>


int main(int argc, char **argv)
{
	int a,b;
	int sum = 0;
		
		for (scanf ("%d %d", &a, &b); a<=b; a++)
		{	 
			sum = sum+(a*a);	
		}
		printf ("%i ", sum);
	
	return 0;
}

