#include <stdio.h>
#include <stdlib.h>
#define N 100
 
int main() { 
    FILE *input, *output ;
	char str[N]={0};
    int i=0, size_str;
    char c;
  
    input = fopen("input.txt", "r");
    output = fopen ("output.txt", "w");
		
	while ((c=fgetc(input)) != '\n')
	{
		str[i++] = c;
		size_str = i; 
	}

	for (i=0; i<(size_str - 1); i++)
	{
		if (str[size_str-1] == str[i])
		{
			fputc((i+'0'), output);
			fputc((' '), output);
		}
	}
	
    fclose(output);
    fclose(input);
    
    return 0;
}
	


