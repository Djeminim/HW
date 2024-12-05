

#include <stdio.h>



int input_array (int a[], int max_size)
{
	int top = 0;
	
	while (1)
	{
		int x;
		scanf("%i", &x);
		if (x==0 || top == max_size) break;
		a[top] = x;
		top++;
	}
	return top;
}

void sort_even_odd(int n, int a[])
{
	int i,k,tmp;
	//static int first_even;
	for (i=0; i<n; i++)
	{
		if (a[i]%2 !=0 )
		{
			k=i;
			
			while (k<n && a[k]%2!=0)
			{
				k++;
				if (a[k]%2==0)
				{
					tmp=a[k];
				}	
								
			}
			
			while (k>i)
			{
				a[k]=a[k-1];
				k--;
			}
			
			a[i]=tmp;
			
		}
	}	
}


void print_array (int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
}

int main(int argc, char **argv)
{
	int allocate_size = 100;
	int a[allocate_size];
	int n;
	
	n = input_array(a, allocate_size);
	sort_even_odd(n, a);
	print_array( a, n);
	
	return 0;
}
	


