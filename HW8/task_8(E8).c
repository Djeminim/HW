

#include <stdio.h>
//Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.


void array_invers (int a)
{

}

int main(int argc, char **argv)
{
	int array[12];
	int invert=3,straght=0,a,invert2=7,straght2=4,invert3=11,straght3=8;
	
	
	
	for(int i=0;i<12;i++)
	{		
		scanf ("%i", &array[i]);	
	}
		for (int i=0;i<12;i++)
	{
		
	if(i<2)
	{
			
		a=array[straght];
		array[straght]= array[invert];
		array[invert]=a;
		
		a=array[straght2];
		array[straght2]= array[invert2];
		array[invert2]=a;
		
		a=array[straght3];
		array[straght3]= array[invert3];
		array[invert3]=a;
		
		invert--;
		invert2--;
		invert3--;
		straght++;
		straght2++;
		straght3++;
		
		
	}
		
		printf("%i ", array[i]);
	}
	
	
	return 0;
}

