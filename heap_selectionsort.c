// Create a heap given an arr.

#include <stdio.h>
#include <stdlib.h>

struct HEAP {
    int* arr;
    int size;
    int limit;
};

typedef struct HEAP* heap;

heap heapify(int limit)
{
    heap a = (heap)malloc(sizeof(struct HEAP));
    a->arr = (int*)malloc(sizeof(int) * limit);
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
    a->arr[a->size] = value;
    a->size++;
}

void Heapsort(heap a)
{
    for (int i = 0; i < a->size; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < a->size; j++)
        {
            if (a->arr[j] < a->arr[smallest])
            {
                smallest = j;
            }
        }
        int temp = a->arr[i];
        a->arr[i] = a->arr[smallest];
        a->arr[smallest] = temp;
    }
}

void print(heap a)
{
    for (int i = 0; i < a->size; i++)
    {
        printf("%d ", a->arr[i]);
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
    Heapsort(a);
    printf("Sorted: ");
    print(a);
    return 0;
}