#include <stdio.h>

int main(int argc, char **argv) 
{
 int a;
 int b=0;
 
 scanf("%i", &a);
 
 while (a>0)
 {
	 b=b+a%10;
	 a=a/10;
 }
 
 printf("%i", b);
 
 return 0;
}
