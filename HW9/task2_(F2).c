

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
	static int tmp,k=0,j=0;
	int i;
	int odd[n];
	int even[n];
	//static int first_even;

	
	for (i=0; i<n; i++)
	{
		
		if (a[i]%2 == 0)
		{
			even[k]=a[i];
			k++;
		}
		
		else if (a[i]%2 != 0)
		{
			odd[j]=a[i];
			j++;
		}
		
	}
	//printf ("k=%d j=%d ", k,j);
	
	for (i=0; i<k; i++)
	{
		a[i]=even[i];
		tmp++;
		
		//printf ("ev=%d odd=%d ", even[i],odd[i]);
		
	}
		//printf ("tpm=%d ",tmp);
	for (i=0; i<j; i++)
	{	
		a[tmp]=odd[i];
		tmp++;
		
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
	


