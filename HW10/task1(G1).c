#include <stdio.h>
#include <stdlib.h>
#define N 1000
 
int main() { 
    FILE *input, *output ;
    char str[N]={0};
    int i=0,n;
    char c;
 
 
  
    input = fopen("input.txt", "r");
    output = fopen ("output.txt", "w");
    //fscanf(file, "%s", str);// Передаём в str до пробела или конца строки
    // 1 символ в 1-ну ячейку массива
    
    while ((c=fgetc(input)) != '\n')
    {
		
		str[i]=c;
		i++;
	}
    n=i;
    printf("%d", i);    

    fprintf(output, "%s, %s, %s %d", str,str,str,n);
    
    
    
  

    fclose(output);
    fclose(input);
    
    return 0;
}
	


