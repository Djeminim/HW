

#include <stdio.h>
//Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.


void array_invers (int a)
{

}

int main(int argc, char **argv)
{
	int array[12],array_1[4],array_2[4];
	
	for(int i=0;i<12;i++)
	{		
		scanf ("%i", &array[i]);	
	}
	
	
	for(int i=0;i<4;i++)
	{			
		array_1[i]=array[i];
		array_2[i]=array[i+4];
		array[i]=array[i+8];
		array[i+4]=array_1[i];
		array[i+8]=array_2[i];	
	}
		
	for(int i=0;i<12;i++)
	{		
		printf("%i ", array[i]);	
	}

	return 0;		
	}

	
	

