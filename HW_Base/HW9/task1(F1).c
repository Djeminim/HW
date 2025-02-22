

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

void sort_array(int size, int a[])
{
	for (int i=1; i<size; i++)
	{
		int k=i;
		while(k>0 && a[k-1] > a[k])
		{
			int tmp = a[k-1];
			a[k-1] = a[k];
			a[k] = tmp;
			--k;
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
	sort_array(n, a);
	print_array( a, n);
	
	return 0;
}
	


