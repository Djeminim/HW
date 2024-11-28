

#include <stdio.h>

int main(int argc, char **argv)
{
	int array[10];
	int invert=4,straght=0,a,invert2=9,straght2=5;
	
	for(int i=0;i<10;i++)
	{		
		scanf ("%i", &array[i]);	
	}
	
	for (int i=0;i<10;i++)
	{
		
		if(i<2)
		{
			
			a=array[straght];
			array[straght]= array[invert];
			array[invert]=a;
		
			a=array[straght2];
			array[straght2]= array[invert2];
			array[invert2]=a;
		
			invert--;
			invert2--;
			straght++;
			straght2++;
		}
		
		printf("%i ", array[i]);
	}
	return 0;
}

