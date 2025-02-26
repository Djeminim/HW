#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Определяем структуру для элемента связного списка
typedef struct list {
    uint64_t address;   // Адрес блока памяти
    size_t size;        // Размер блока памяти
    char comment[64];   // Комментарий
    struct list *next;  // Указатель на следующий элемент списка
} list;

// Функция для поиска адреса блока памяти с максимальным размером
uint64_t findMaxBlock(list *head)
{
    // Если список пуст
    if (head == NULL)
    {
        return 0; // Возвращаем 0
    }

    uint64_t maxAddress = head->address; // Инициализируем maxAddress
    size_t maxSize = head->size;       // Инициализируем maxSize
    list *current = head->next;       // Начинаем со второго элемента

    // Обходим список
    while (current != NULL)
    {
        // Если текущий элемент больше максимального
        if (current->size > maxSize)
        {
            maxSize = current->size;       // Обновляем maxSize
            maxAddress = current->address; // Обновляем maxAddress
        }
        current = current->next;           // Переходим к следующему элементу
    }

    return maxAddress; // Возвращаем адрес
}

int main()
{
    list *head = NULL;  // Указатель на начало списка
    list *tail = NULL;  // Указатель на конец списка
    int numBlocks;      // Количество блоков

    printf("Enter the number of blocks: "); // Запрашиваем количество блоков
    scanf("%d", &numBlocks);              // Считываем количество блоков

    // Создаем блоки
    for (int i = 0; i < numBlocks; i++)
    {
        list *newNode = (list*)malloc(sizeof(list)); // Выделяем память
        if (newNode == NULL)
        {
            fprintf(stderr, "Memory allocation error for block %d\n", i + 1); // Сообщение об ошибке

            //деелаем указатель на указатель на начало списка как отправную точку
            list *current = head;
            
            //процесс отчиски памяти всех вложенных структур
            while (current != NULL)
            {
                //записываем в поле структуры next адрес вложенной структуры из текушей структуры
                list *next = current->next;
                free(current); //очищаем current т.к. его адрес переписан в next
                current = next; 
            }
            return 1; // Возвращаем код ошибки
        }

        printf("Enter address and size for block %d: ", i + 1); // Запрашиваем адрес и размер
        scanf("%llu %zu", &newNode->address, &newNode->size);   // Считываем адрес и размер

        printf("Enter comment for block %d: ", i + 1); // Запрашиваем комментарий
        scanf(" %63s", newNode->comment);// Считываем комментарий (ограничение длины)

        newNode->next = NULL; // Указываем, что это последний элемент

        // Добавляем элемент в список
        if (head == NULL)
        {
            // Первый элемент
            head = newNode;    // head указывает на новый элемент
            tail = newNode;    // tail указывает на новый элемент
        }
        else
        {
            // Не первый элемент
            tail->next = newNode; // Добавляем в конец списка
            tail = newNode;       // Обновляем tail
        }
    }

    uint64_t maxBlockAddress = findMaxBlock(head); // Находим адрес макс. блока

    printf("Address of the largest block: %llu\n", maxBlockAddress); // Выводим результат

    // Освобождаем память 
    list *current = head;
    while (current != NULL)
    {
        list *next = current->next;
        free(current);
        current = next;
    }

    return 0; // Завершаем программу
}