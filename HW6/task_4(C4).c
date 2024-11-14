#include <stdio.h>



int main()
{
	int a,n,i=0,max=0;
	int array[100];
	
	do
	{
		scanf("%i", &a);
		array[i]=a;
		i++;
		n=a;
	}
	while (n!=0);
	
	for(int x=0;x<i;x++)
	{
		if(array[x]>=-2 && array[x]<2 && array[x]!=0)
		{
		array[x]=(array[x]*array[x]);
		}
		
		else if (array[x]>=2)
		array[x] = ((array[x]*array[x])+(array[x]*4)+5);
		
		else if (array[x]<-2)
		array[x]=4;
		
	}
	 
	
	for (int x=0;x<(i-1);x++)
	{
		
		 if (max<=array[x])
		 max=array[x];

	}
	 printf("%i ", max);
	    
    return 0;
}

