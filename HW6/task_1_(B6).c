#include <stdio.h>

int main(int argc, char **argv) 
{
 int a,b;
 
 scanf("%i", &a);
 
 for (int i=0; i<=a; )
 {
	 b=a%10;
	 a=a/10;
	 
	 if (a%10 == b && a!=0)
	 {
		 printf("YES ");
		 break;	 			
	 }
	 	
	 if (a==0)
	{
		printf("NO ");
		break; 
	} 
 }
 

 return 0;
}
