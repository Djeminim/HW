
#include <stdio.h>

int main(int argc, char **argv)
{
	int array[5];
	float result=0;
	
	for (int i;i<5;i++)
	{
		scanf("%i", &array[i]);
		result=result+array[i];
	}
	printf ("%.3f", (result/5));
	return 0;
}
