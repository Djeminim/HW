#include <stdio.h>
#include <stdlib.h>
#define N 1000
 
int main() { 
    FILE *input, *output ;
    char str[N]={0};
    int i=0,n;
    char c = 'A',b = '2';
 
 
  
    input = fopen("input.txt", "r");
    output = fopen ("output.txt", "w");

	fscanf(input, "%d", &n); //Передаём в str до пробела или конца строки 1 символ в 1-ну ячейку массива
 
    for (i=0; i<n; i++)
    {
		str[i] = c;
		str[++i] = b;
		 
		if (c >= 'A' && c < 'Z') 
		c++;
		else 
		c='A';
		
		if (b >= '2' && b < '8')
		b+=2;
		else
		b = '2';
		
	} 
    
    fprintf(output, "%s", str);
    
    
  

    fclose(output);
    fclose(input);
    
    return 0;
}
	


