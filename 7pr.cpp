#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct list_t
{
    int value;
    struct list_t* next;
}  TList;
TList* Push(TList** list, int value)
{
    TList* node = (TList*)malloc(sizeof(TList));
    node->value = value;
    node->next = *list;

    *list = node;

    return *list;
}
TList* Find(TList* list, int value)
{
    for (; list && (list->value != value); list = list->next) { ; }

    return list;
}
void Print(TList* list)
{
    for (; list; list = list->next)
    {
        printf("%d ", list->value);
    }
    printf("\n");
}
int Random(int min, int max)
{
    return (rand() % (max - min) + min);
}
TList* GetGenList(size_t count, int min, int max)
{
    TList* list = NULL;

    while (count--)
    {
        Push(&list, Random(min, max));
    }

    return list;
}
TList* GetUniqueFirst(TList* first, TList* second)
{
    TList* list = NULL;

    for (; first; first = first->next)
    {
        if (!Find(list, first->value) && !Find(second, first->value))
        {
            Push(&list, first->value);
        }
    }

    return list;
}

int main()
{
    srand(time(NULL));
    TList* l1 = GetGenList(10, 3, 10);
    TList* l2 = GetGenList(10, 0, 7);
    TList* l = GetUniqueFirst(l1, l2);

    printf("L1: "); Print(l1);
    printf("L2: "); Print(l2);
    printf("L : "); Print(l);

    return 0;
}