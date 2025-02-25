#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

int main ()
{
    list *head = NULL;
    list *tail = NULL;

    int numBlocks;
    printf("Enter number blocks");
    scanf("%d", &numBlocks);

    if(numBlocks == NULL)
    printf("%d", numBlocks);

    //создание связанного списка
    for(int i; i < numBlocks; i++)
    {
        list *newNode = (list*)malloc(sizeof(list));

        if (numBlocks == NULL)
        {
            fprintf(stderr, "Error memory allocation %d", (i+1));

            list *current = head;
    
            while(current != NULL)
            {
                list *next = current ->next;
            }
        }

    }
}