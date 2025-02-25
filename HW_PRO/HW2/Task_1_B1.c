#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определение структуры list
typedef struct list
{
    void *address;     // Адрес блока памяти
    size_t size;        // Размер блока памяти
    char comment[64];   // Комментарий
    struct list *next;  // Указатель на следующий элемент списка
} list;

// Функция для подсчета общего объема используемой памяти
size_t totalMemoryUsage(list *head)
{
    size_t totalSize = 0; // Инициализируем общий размер 0
    list *current = head;   // Указатель на текущий элемент, начинаем с головы списка

    // Обходим список
    while (current != NULL)
    {
        totalSize += current->size;  // Увеличиваем общий размер на размер текущего блока
        current = current->next;    // Переходим к следующему элементу
    }

    return totalSize; // Возвращаем общий размер
}

// Пример использования (для тестирования)
int main()
{
    list *head = NULL;
    list *tail = NULL;
    int numBlocks;

    printf("Enter the number of blocks: ");
    scanf("%d", &numBlocks);

    for (int i = 0; i < numBlocks; i++)
    {
        list *newNode = (list*)malloc(sizeof(list));
        if (!newNode)
        {
            fprintf(stderr, "Memory allocation error for block %d\n", i + 1);
            // Освобождаем память для уже созданных элементов
            list *current = head;
            while (current != NULL)
            {
                list *next = current->next;
                free(current);
                current = next;
            }
            return 1;
        }

        printf("Enter address and size for block %d: ", i + 1);
        scanf("%p %zu", &newNode->address, &newNode->size);

        printf("Enter comment for block %d: ", i + 1);
        scanf(" %63s", newNode->comment);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    size_t totalUsage = totalMemoryUsage(head);
    printf("Total memory usage: %zu bytes\n", totalUsage);

    // Освобождаем память
    list *current = head;
    while (current != NULL)
    {
        list *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}