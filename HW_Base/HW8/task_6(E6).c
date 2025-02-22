

#include <stdio.h>

int main(int argc, char **argv)
{
	float array[12];
	float average=0;
	
	
	for (int i=0;i<12;i++)
	{
		scanf("%f", &array[i]);
	}
		
	
		
	for (int i=0;i<12;i++)
	{
		
			average=average + array[i];
						
	}	

	printf ("%.2f", (average/12));
	return 0;
}

