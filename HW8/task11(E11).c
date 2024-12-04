

#include <stdio.h>

int main(int argc, char **argv)
{
	int array[10];
	

	for(int i=0;i<10;i++)
	{		
		scanf ("%i", &array[i]);	
	}
	
	for (int i=0;i<10;i++)
	{
		int k = i;
		while (k>0 && (array[k-1]%10) > (array[k]%10))
		{
			int tmp = array[k-1];
			array[k-1]=array[k];
			array[k]=tmp;
			k--;
		}
	}
	
	for(int i=0;i<10;i++)
	{		
		printf ("%i ", array[i]);	
	}
	
	return 0;
}

