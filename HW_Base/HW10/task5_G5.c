#include <stdio.h>
#include <stdlib.h>
#define N 100
 
int main() { 
    FILE *input, *output ;
	char str[N]={0};
	char letter[N]={0};
    int i=0, size_str, repeat_counter = 0, size_letter;
    char c, first_word = 0;
  
    input = fopen("input.txt", "r");
    output = fopen ("output.txt", "w");
		
	while ((c=fgetc(input)) != '\n')
	{
		if(c == 'a')
		str[i] = 'b';
		
		else if(c == 'b')
		str[i] = 'a';
		
		else if(c == 'A')
		str[i] = 'B';
		
		else if(c == 'B')
		str[i] = 'A';
		
		else
		str[i] = c;
		
		i++;

	}
	
	fprintf(output, "%s", str);
	
    fclose(output);
    fclose(input);
    
    return 0;
}
	


