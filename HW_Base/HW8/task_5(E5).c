#include <stdio.h>

int main(int argc, char **argv)
{
	int array[10];
	int positive=0;
	
	
	for (int i=0;i<10;i++)
	{
		scanf("%i", &array[i]);
	}
		
	
		
	for (int i=0;i<10;i++)
	{
		
		if(array[i]>0 )
		{
			positive=positive + array[i];
					
		}	
	}	

	printf ("%i", (positive));
	return 0;
}

