#include <stdio.h>

int main(int argc, char **argv) 
{
 int a;
 
 scanf("%i", &a);
 
 a=a/100;
 if (a<10 && a>=1)
 printf("YES");
 else
  printf("NO");
 
 return 0;
}
