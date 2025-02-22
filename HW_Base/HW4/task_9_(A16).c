#include <stdio.h>

int main(int argc, char **argv) 
{
	int array [33];
	
	for (int i=0;i<3;i++)
	{
		scanf ("%d", &array[i]);			
	}
	
	if (array[0]<array[1] && array[0]<array[2])
	printf ("%s", "YES");
		
	else
	printf ("%s", "NO");
	
	
	
}

