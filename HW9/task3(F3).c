

#include <stdio.h>
#include <limits.h>


//int input_array (int a[], int max_size)
//{
	//int top = 0;
	
	//while (1)
	//{
		//int x;
		//scanf("%i", &x);
		//if (x==0 || top == max_size) break;
		//a[top] = x;
		//top++;
	//}
	//return top;
//}

//void score(int n, int a[])
//{
	
//}


//void print_array (int a[], int n)
//{
	//for (int i=0; i<n; i++)
	//{
		//printf ("%d ", a[i]);
	//}
//}

int main(int argc, char **argv)
{
	//int allocate_size = 100;
	//int a[allocate_size];
	//int n;
	
	//n = input_array(a, allocate_size);
	//score(n, a);
	//print_array( a, n);
	
	unsigned long int b;
	int i=0;
	int figure[10] = {0};
	int tmp [1000] = {0};

	scanf ("%s", tmp);
	printf("%s", tmp[0])
	if (b == 0)
	{
		figure[0]++;
	}
	
	while (b > 0)
	{
		figure[b % 10]++;
		b = b/10;
	}

		
	for (i=0; i<10; i++)
	{
		if( figure[i]>0 )
		printf("%i %i\n", i,figure[i]);
	}
	return 0;
}
	


