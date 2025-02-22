

#include <stdio.h>

int main(int argc, char **argv)
{
	int array[5];
	int min;
	
	for (int i=0;i<5;i++)
	{
		scanf("%i", &array[i]);
	}
	
	min=array[0];
	
	for (int i=0;i<5;i++)
	{
		if(min>array[i])
		min=array[i];
	}
	
	printf ("%i", (min));
	return 0;
}

