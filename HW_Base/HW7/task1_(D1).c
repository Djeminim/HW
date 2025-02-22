
#include <stdio.h>

unsigned int queue(unsigned int a) 
{	
	
    if (a<1) return 1;
	
	static int f=0;
	f++;
	printf ("%i ", f);
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

