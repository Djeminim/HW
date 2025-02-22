//Выведите все цифры по одной, в обратном порядке
#include <stdio.h>

int reverseDigits(int num) 
{	
	int rev_num = 0;
	if (num == 0)
	{
		printf("%d ", (0));
	}
    while (num > 0) 
    {
		printf("%d ", (num % 10));
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
        
    }
    return rev_num;
}



int main(int argc, char **argv)
{
	int num;
	scanf("%i", &num);
	reverseDigits(num);
	
	return 0;
}
