#include <stdio.h>
#include <stdint.h>

int main() 
{
    uint32_t n;
    unsigned int k;

    // Считываем N и K
    scanf("%u %u", &n, &k);

    // Обеспечиваем цикличность сдвига
    k %= 32;

    // Сдвигаем n вправо
    uint32_t right = (n >> k);

    // Сдвигаем n влево
    uint32_t left = (n << (32 - k));

    // Объединяем результаты
    uint32_t shifted_n = right | left;

    // Выводим результат
    printf("%u\n", shifted_n);

    return 0;
}