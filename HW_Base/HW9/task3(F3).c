

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
	
	int i=0;
	int  tmp [1000] = {0};
	char c;
	
	while ((c=getchar()) != '\n')
	{
		tmp[(c-'0')]++;	
	}
	
	//size_t size_tmp = (sizeof(tmp)/sizeof(tmp[0]));
	
	for (i=0; i<10; i++)
	{
		if (tmp[i] != 0)
		{
			printf("%i %i\n", i,tmp[i]);
		}
	}
	
	return 0;
}
	


