
#include <stdio.h>

void print_simple(int n)
{
	
	for (int i=1;i<=n;i++)
	{
		if ((n%i)==0)
		printf("%i ", i);

	}

}

int main(int argc, char **argv)
{
	int n;
	scanf("%i", &n);
	print_simple(n);
	return 0;
}
