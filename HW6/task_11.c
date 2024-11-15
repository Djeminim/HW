
#include <stdio.h>

void print_simple(int n)
{
	int f;

	for (int i=2;i<=f;i++)
	{
		
		if ((f%i)==0)
		{	
			f=f/i;
			printf("%i ", i);
			--i;
		}
	}

}

int main(int argc, char **argv)
{
	int n;
	scanf("%i", &n);
	print_simple(n);
	return 0;
}

