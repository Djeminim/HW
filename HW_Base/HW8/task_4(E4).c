

#include <stdio.h>

int main(int argc, char **argv)
{
	int array[10];
	int max1= (-2147483648),max2= (-2147483648),a;
	
	
	for (int i=0;i<10;i++)
	{
		scanf("%i", &array[i]);
	}
		
	
		
	for (int i=0;i<10;i++)
	{
		
		if(max1<array[i] )
		{
			max1=array[i];
			a=i;
				
		}	
	}	
	for (int i=0;i<10;i++)
	{
		if(max2<array[i] && a!=i)
		{
			max2=array[i];			
		}	
	}	
	printf ("%i", (max1+max2));
	return 0;
}

