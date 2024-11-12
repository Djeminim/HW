#include <stdio.h>



int main()
{
	int a,n,i=0,max;
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
		
		if (array[x]>=2)
		array[x] = ((array[x]*array[x])+(array[x]*4)+5);
		
		if (array[x]<-2)
		array[x]=4;
		
	}

	
	for (int x=0;x<i;x++)
	{
		 if (array[x]>=array[x-1])
		 max=array[x];
		 
	}
	 printf("%i", max);
	    
    return 0;
}

