#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* node;

node createNode(int data)
{
    node new_Node = (struct Node *)malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->left = NULL;
    new_Node->right = NULL;
    return new_Node;
}

node insert(node root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void print(node root)
{
    if (root == NULL)
        return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

int main()
{
    int arr[] = { 10, 21, 32, 44, 52, 61, 79 };
    int n = sizeof(arr) / sizeof(arr[0]);
    node root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    print(root);
    return 0;
}