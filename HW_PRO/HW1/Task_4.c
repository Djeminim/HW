#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n;
    int k;

    // Ввод данных
    scanf("%u", &n);

    scanf("%d", &k);

    // Проверка корректности ввода K
    if (k < 1 || k > 31)
    {
        printf("Ошибка: K должно быть в диапазоне от 1 до 31.\n");
        return 1;
    }

    uint32_t max_value = 0; // Максимальное значение, которое мы нашли

    // Перебираем все возможные стартовые позиции для K бит
    for (int i = 0; i <= 32 - k; ++i)
    {
        // Создаем маску для выделения K бит, начинающихся с позиции i
        uint32_t mask = ((1U << k) - 1) << i;

        // Выделяем K бит из числа N и сдвигаем их к младшим битам
        uint32_t current_value = (n & mask) >> i;

        // Если текущее значение больше максимального, обновляем максимальное значение
        if (current_value > max_value)
        {
            max_value = current_value;
        }
    }

    // Вывод результата
    printf("%u\n", max_value);
    return 0;
}