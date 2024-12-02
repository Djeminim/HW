

#include <stdio.h>

int main(int argc, char **argv)
{
	int array[10];
	int array_1[
	int invert=4,straght=0,a,invert2=9,straght2=5;
	
	for(int i=0;i<10;i++)
	{		
		scanf ("%i", &array[i]);	
	}
	
	for (int i=0;i<10;i++)
	{
		if (array[i+1]%10 >= array[i]%10 )
		{
			
		}
		array[i]=array[i]%10;
		printf ("%i ", array[i]);
	}
	return 0;
}

