#include <stdio.h>
#include <string.h>


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

int find_max_array(int size, int a[])
{
	return 0;
}


int main(int argc, char **argv)
{

	int i=0, allocate_size = 1000;
	int  a[1000] = {0};

	
	int n = input_array(a, allocate_size);
	find_max_array(n,a);
	
	return 0;
}


