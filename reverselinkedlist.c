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

void reverse()
{
    node prev = NULL;
    node current = HEAD;
    node next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    HEAD = prev;
}

int main()
{
    insert(34);
    insert(234);
    insert(3);
    insert(523);
    print();
    reverse();
    print();
    return 0;
}