// Implement a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node* node;
node HEAD = NULL;
node current = NULL;

void insert(int data)
{
    node new_Node = (struct Node *)malloc(sizeof(struct Node));
    if(HEAD == NULL)
    {
        HEAD = new_Node;
        current = new_Node;
    }
    current->next = new_Node;
    current = new_Node;
    current->data = data;
}

// Selection Sort on the linked list.
void Selection_Sort()
{
    node temp = HEAD;
    node smallest = NULL;
    node temp0 = NULL;
    int value_temp = 0;
    while (temp != NULL)
    {
        smallest = temp;
        temp0 = temp->next;
        while (temp0 != NULL)
        {
            if (temp0->data < smallest->data)
            {
                smallest = temp0;
            }
            temp0 = temp0->next;
        }
        value_temp = temp->data;
        temp->data = smallest->data;
        smallest->data = value_temp;
        temp = temp->next;
    }
}

void print()
{
    node temp = HEAD;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert(34);
    insert(2);
    insert(30);
    insert(65);
    insert(9);
    print();
    Selection_Sort();
    printf("Sorted: ");
    print();
    return 0;
}