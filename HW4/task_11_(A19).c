#include <stdio.h>

int main(int argc, char **argv) 
{
 int array [3];
 int a;
 
 for(int i=0;i<3;i++)
 {
	 scanf("%i", &a);
	 array[i]=a;	 
 }	 
	 if (((array[0]+array[1]) > array[2])&&((array[0]+array[2])>array[1])
	 &&(array[1]+array[2])>array[0])
	 printf("YES");
	 
	 else
	 printf("NO");
	 
	return 0;
}
