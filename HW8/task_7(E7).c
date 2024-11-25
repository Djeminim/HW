

#include <stdio.h>

int main(int argc, char **argv)
{
	int array[10], revers[10];
	int invert=10,straght=0;
	
	for(int i=0;i<10;i++)
	{		
		scanf ("%i", &array[i]);	
	}
	
	for (int i=10;i>=0;i++)
	{
		revers[invert]=array[straght];
		invert--;
		straght++;
		printf ("%i", revers[invert] );
	}
	return 0;
}

