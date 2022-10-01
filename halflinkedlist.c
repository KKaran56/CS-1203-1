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

void halFlinkedlist()
{
    node tortoise = HEAD;
    node hare = HEAD;
    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    while (tortoise != NULL)
    {
        printf("%d ", tortoise->data);
        tortoise = tortoise->next;
    }
    printf("\n");
}

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

int main()
{
    insert(22);
    insert(235);
    insert(54);
    insert(546);
    insert(345);
    insert(457);
//    insert(7);
//    insert(8);
//    insert(9);
//    insert(10);
    print();
    halFlinkedlist();
    return 0;
}



