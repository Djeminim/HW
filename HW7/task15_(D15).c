
//Выведите все нечетные числа из этой последовательности, сохраняя их порядок
#include <stdio.h>


#include <stdio.h>
 
int max_find(int max)
{
	int input;
    scanf("%d", &input);
    if (input == 0)
        return max;
    if ((max == 0) || (input > max))
        max = input;
    return max_find(max);
}
 
int main()
{
    printf("%d", max_find(0));


    return 0;
}


 



