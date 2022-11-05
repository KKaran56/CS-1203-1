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

void Quick_Sort(node head, node tail)
{
    if (head == tail)
        return;
    node pivot = head;
    node i = head;
    node j = head->next;
    while (j != tail)
    {
        if (j->data < pivot->data)
        {
            i = i->next;
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
        j = j->next;
    }
    int temp = i->data;
    i->data = pivot->data;
    pivot->data = temp;
    Quick_Sort(head, i);
    Quick_Sort(i->next, tail);
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
    Quick_Sort(HEAD, NULL);
    printf("Sorted: ");
    print();
    return 0;
}