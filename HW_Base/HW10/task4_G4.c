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
		if (first_word == 0)
		{
			str[i++] = c;
			size_str = i; 
		}
		
		if (c == ' ' || first_word == 1)
		{
			first_word = 1;
			
			for (i=0; i<size_str; i++)
			{
				if (str[i] == c && c != ' ')
				{
					if (letter[repeat_counter] == c)
					{
						letter[repeat_counter] = '\0';						
						break;
					}
					
					else
					{
						letter[repeat_counter] = c;
					}					
				}
			}
			
			if(letter[repeat_counter] != '\0')
			repeat_counter++;
			size_letter = repeat_counter;
		}		
	}
	
	for (i=0; i<size_letter; i++)
	{
		repeat_counter = 0;
		
		for(int b=0; b<size_letter; b++)
		{
			if(letter[b] == letter[i])
			{
				repeat_counter++;
			}
		}
		
		
		if (repeat_counter == 1 )
		{
			fputc (letter[i], output);
			fputc (' ', output);
		}
	}
	
    fclose(output);
    fclose(input);
    
    return 0;
}
	


