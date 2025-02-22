#include <stdio.h>
#include <string.h>

void print_digit(char s[])
{
	int tmp[10] = {0};
	int i=0;
	
	int size_s = strlen(s);
	size_t size_tmp = (sizeof(tmp)/sizeof(tmp[0]));
	
	for (i=0; i<size_s; i++)
	{
		if (s[i] >= '0' && s[i]<='9')
		{
			tmp[(s[i]-'0')]++;	
		}
	}
	
	
	
	for (i=0; i<size_tmp; i++)
	{
		if (tmp[i] != 0)
		{
			printf("%i %i\n", i,tmp[i]);
		}
	}
}

int main(int argc, char **argv)
{

	int i=0;
	char  s[1000] = {0};
	char c;
	
	while ((c=getchar()) != '\n')
	{
		s[i]=c;
		i++;

	}
	
	print_digit(s);
	
	return 0;
}


