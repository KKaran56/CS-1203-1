// Create a heap given an array.

#include <stdio.h>
#include <stdlib.h>

struct HEAP {
    int* array;
    int size;
    int limit;
};

typedef struct HEAP* heap;

heap heapify(int limit)
{
    heap a = (heap)malloc(sizeof(struct HEAP));
    a->array = (int*)malloc(sizeof(int) * limit);
    a->size = 0;
    a->limit = limit;
    return a;
}

void insert(heap a, int value)
{
    if (a->size == a->limit)
    {
        printf("Heap full.\n");
        return;
    }
    a->array[a->size] = value;
    a->size++;
}

void print(heap a)
{
    for (int i = 0; i < a->size; i++)
    {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

int main()
{
    heap a = heapify(6);
    insert(a, 534);
    insert(a, 34);
    insert(a, 9);
    insert(a, 854);
    insert(a, 23);
    insert(a, 99);
    print(a);
    return 0;
}