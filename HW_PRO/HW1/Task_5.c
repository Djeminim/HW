#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n;
    int count = 0; // Счетчик единичных битов

    // Ввод данных
    scanf("%u", &n);

    // Подсчет единичных битов
    while (n != 0)
    {
        count += n & 1; // Проверяем младший бит и добавляем его к счетчику
        n >>= 1;        // Сдвигаем число вправо на 1 бит
    }

    // Вывод результата
    printf("%d\n", count);

    return 0;
}