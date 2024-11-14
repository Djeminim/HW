
#include <stdio.h>

int factorial(int a)
{
	int f=1;
	for (int i=1;i<=a;i++)
	{
		f=f*(i);

	}
	return (printf("%i\n", f));
}

int main(int argc, char **argv)
{
	int n;
	scanf("%i", &n);
	factorial(n);
	return 0;
}

