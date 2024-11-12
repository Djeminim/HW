#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%i %i", &a,&b);
    
    
    c=a; 
	for (int i=1;i<b;i++)
	{
		a=a*c;		
	}
   
   if(b<=0) printf("%i", a=1);  
   else printf("%i", a);    
    return 0;
}


/*
 #include <stdio.h>
int main()
{
    char c;
    while( (c=getchar())!='\n') //спец символ новой строки
        if(c>='a' && c<='z') //все символы лежат подряд ‘a’=97, ‘b’=98, ‘c’=99, ...
                 putchar('A' + (c-'a'));
        else
                 putchar(c);
    return 0;
}

*/
