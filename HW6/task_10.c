#include <stdio.h>

void print_simple(int n)
{
	int f=2;

	while (n/f>=1 )
	{
		if (n%f==0)
		{
			while (n%f==0)
			{
				printf ("%i ", f);
				n=n/f;			
			}		
		}
		
		else if (n%f!=0)
		f=f+1;
		
	}

}

int main()
{
	int n;
	scanf("%i", &n);
	print_simple(n);
	return 0;
	
}

