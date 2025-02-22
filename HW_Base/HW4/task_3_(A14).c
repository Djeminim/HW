#include <stdio.h>

int main(int argc, char **argv) 
{
    int a,b,c,value ;
    scanf ("%i", &value);
    
    a = value/100;
    b = (value/10)-(10*a);
    c = value-((a*100)+(b*10));
    
    if (a>=c && a>=b) printf("%i", a);
    else if (b>a && b>c) printf("%i", b);
    else printf("%i", c);
	  
    return 0;
}

