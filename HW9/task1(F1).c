

#include <stdio.h>

void sort_array(int size, int a[])
{
	int b;
	
	for (int i=0; i<size-1; i++)
	{
			
		if (a[i] >= a[i+1])
		{
			b=a[i+1];
			a[i+1]=a[i];
			a[i]=b;
			
			for (int g=i; g>0; g--)
			{
				if (a[i]<=a[i-1])
				{
					b=a[g-1];
					a[g-1]=a[g];
					a[g]=b;
				}		
			}
		}	 
	}
	
	for (int i=0; i<size; i++)
	{
		printf("%i ", a[i]);
	}

}

int main(int argc, char **argv)
{
	
	int a[4];
	
	for (int i=0; i<4; i++)
	{
		scanf("%i", &a[i]);
	}
	
	int lenghtch = sizeof(a)/sizeof(a[0]);
	
	sort_array(lenghtch, a);
	
	return 0;
}
	


