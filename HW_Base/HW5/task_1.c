

#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	int array [100];
	
	scanf ("%i", &a);
	
	for (int i=1; i<=a; i++)
	{
		array[i]=i*i;
		array[i+1] = (i*i*i);
		
		printf("%i %i %i\n", i, array[i], array[i+1]);
	}
	return 0;
}

