
#include <stdio.h>

 void nod(int a, int b)
{	
	int maxA,maxB;
	int f,c=2;
	
	if (a>b)f=a;
	else f=b;

	for(int i=0;i<=f;i++)
	{
		if(a%b==0)
		{
			maxA=a/b;
		}
		else if (b%a==0)
		{
			maxB=b/a;
		}
		else
		{
			if (a%b!=0 && b%a!=0)
			{
				while (a%b!=0 || b%a!=0)
				{
					a=a/c;
					b=b/c;
					if (a%b==0)
					{
						
					}
				}
			}
		}
	}

	while (a/f>=1 && b/f>=1)
	{
		if (a%f==0 && b%f==0)
		{
			printf ("%i ", f);
			maxA=a/f;
			maxB=b/f;					
		}		
		f=f+1;	
	}
}

int main()
{
	int a,b;
	scanf("%i %i", &a,&b);
	nod(a,b);
	return 0;
	
}

