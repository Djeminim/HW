#include <stdio.h>

int main(int argc, char **argv) 
{
	int array [2];
	
	for (int i=0;i<2;i++)
	{
		scanf ("%d", &array[i]);			
	} 
	
	if (array[0]>array[1])
	printf ("%s", "Above");
	
	else if(array[0]<array[1])
	printf ("%s", "Less");
	
	else 
	printf ("%s", "Equal");
}

