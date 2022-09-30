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

void print()
{
    node temp = HEAD;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    return 0;
}