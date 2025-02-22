#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Некорректный ввод: N должно быть больше 0.\n");
        return 1; // Выход с кодом ошибки
    }

    int max_val;
    int count = 0;

    // Читаем первое число и инициализируем максимум
    int first_num;
    scanf("%d", &first_num);
    max_val = first_num;
    count = 1; // Первый элемент - это пока что максимум

    // Читаем остальные числа и обновляем максимум и счетчик
    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num > max_val) {
            max_val = num;
            count = 1; // Новый максимум, сбрасываем счетчик
        } else if (num == max_val) {
            count++; // Увеличиваем счетчик, если число равно максимуму
        }
    }

    printf("%d\n", count);

    return 0;
}