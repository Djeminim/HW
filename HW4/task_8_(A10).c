#include <stdio.h>

int main(int argc, char **argv) 
{
	int array [5];
	
	for (int i=0;i<5;i++)
	{
		scanf ("%d", &array[i]);			
	}
	
	int min = array[0];
	
	for (int i=1;i<5;i++)
	{	

		
		if (min>=array[i])
		min = array[i];
	}
	
	
	printf ("%d \n", min);
}

