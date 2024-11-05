#include <stdio.h>

int main(int argc, char **argv) 
{
    int a,b,c ;
    scanf ("%i %i %i", &a,&b,&c);
    
    if (a>=c && a>=b) printf("%i", a);
    else if (b>a && b>c) printf("%i", b);
    else printf("%i", c);
	  
    return 0;
}
