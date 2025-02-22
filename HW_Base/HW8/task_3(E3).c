

#include <stdio.h>

int main(int argc, char **argv)
{
	int array[10];
	int min,max,numMAX=1,numMIN=1;
	
	
	for (int i=0;i<10;i++)
	{
		scanf("%i", &array[i]);
	}
		
	min=array[0];
	max=array[0];	
		
	for (int i=0;i<10;i++)
	{
		
		if(min>array[i])
		{
			min=array[i];
			numMIN=i+1;	
		}
		
		if(max<array[i])
		{
			max=array[i];
			numMAX=i+1;	
		}	
	}
	printf ("%i %i %i %i ", numMAX,max,numMIN,min);
	return 0;
}

