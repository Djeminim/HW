#include <stdio.h>

int main(int argc, char **argv) 
{
    int m , n ;
    scanf ("%i %i", &m,&n);
    m >= n ? printf("%d  %d", n,m) : printf("%d %d", m,n);
    return 0;
}
