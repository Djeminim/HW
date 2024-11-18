//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
#include <stdio.h>

unsigned int queue(unsigned int a) 
{	
	static int f=0;
	
    if (a<1)
    { 
		printf ("%i ", f);
		return 1;
	}
	
	f = f+a;
	queue(a-1);
	
    return a;
}


int main(int argc, char **argv)
{
	static int a;
	scanf("%i", &a);
	queue(a);
	return 0;
}

