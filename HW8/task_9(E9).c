

#include <stdio.h>
//Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.


void array_invers (int a)
{

}

int main(int argc, char **argv)
{
	int array[10];
	int a;
	
	for(int i=0;i<10;i++)
	{		
		scanf ("%i", &array[i]);	
	}
	
	a =  array[9];
	
	for(int i=9;i>=0;i--)
	{	
		if (i == sizeof(array)/sizeof(array[0]))
		{			
			array[i]=array[0];
		}
		
		else if (i<=9 && i>0)
		{
			array[i]=array[i-1];
		}
		
		else if (i==0)
		array[i]=a;	
		
	}
		
	for(int i=0;i<10;i++)
	{		
		printf("%i ", array[i]);	
	}

	return 0;		
	}

	
	

