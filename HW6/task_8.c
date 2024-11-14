
#include <stdio.h>

int main(int argc, char **argv)
{
	char c;
	while ((c=getchar())!='.')
		if (c>='a' && c<='z')
		putchar('Z'-('z'-c) );
		else
		putchar(c);

	return 2;
}

