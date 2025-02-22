#include <stdio.h>
#include <stdint.h>

int extractExp(float num)
{
    union 
    {
        float f;
        uint32_t i;
    } data;

    data.f = num;

    // Извлекаем EXP (8 бит, начиная с 23-го бита)
    uint32_t exp = (data.i >> 23) & 0xFF;

    return (int)exp;
}

// Пример использования (main функция)
int main()
{
    float num;

    scanf("%f", &num);

    int exponent = extractExp(num);

    printf("%d\n", exponent);

    return 0;
}