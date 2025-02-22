#include <stdio.h>
#include <string.h>

int main() 
{
	int x,l,a,b,c,value;
 
    scanf("%i", &value); 
    a = value/100;
    b = (value/10)-(10*a);
    l = (value/10);
    c = value-(l*10);
    x = a*b*c;
      
    printf("%i \n", x );
}

