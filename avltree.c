#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int value;
    struct NODE* left;
    struct NODE* right;
    int height;
};

typedef struct NODE* node;

node Node_Create(int value)
{
    node a = (node)malloc(sizeof(struct NODE));
    a->value = value;
    a->left = NULL;
    a->right = NULL;
    a->height = 1;
    return a;
}

int get_Max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

int get_Height(node a)
{
    if (a == NULL)
    {
        return 0;
    }
    return a->height;
}

int get_Balance(node a)
{
    if (a == NULL)
    {
        return 0;
    }
    return get_Height(a->left) - get_Height(a->right);
}

node Rotate_Right(node x)
{
    node y = x->left;
    node z = y->right;
    y->right = x;
    x->left = z;
    x->height = get_Max(get_Height(x->left), get_Height(x->right)) + 1;
    y->height = get_Max(get_Height(y->left), get_Height(y->right)) + 1;
    return y;
}

node Rotate_Left(node x)
{
    node y = x->right;
    node z = y->left;
    y->left = x;
    x->right = z;
    x->height = get_Max(get_Height(x->left), get_Height(x->right)) + 1;
    y->height = get_Max(get_Height(y->left), get_Height(y->right)) + 1;
    return y;
}

// insert function
node insert(node a, int data)
{
    if (a == NULL)
    {
        return Node_Create(data);
    }
    if (data < a->value)
    {
        a->left = insert(a->left, data);
    }
    else if (data > a->value)
    {
        a->right = insert(a->right, data);
    }
    else
    {
        return a;
    }
    a->height = get_Max(get_Height(a->left), get_Height(a->right)) + 1;
    int balance = get_Balance(a);
    if (balance > 1 && data < a->left->value)
    {
        return Rotate_Right(a);
    }
    if (balance < -1 && data > a->right->value)
    {
        return Rotate_Left(a);
    }
    if (balance > 1 && data > a->left->value)
    {
        a->left = Rotate_Left(a->left);
        return Rotate_Right(a);
    }
    if (balance < -1 && data < a->right->value)
    {
        a->right = Rotate_Right(a->right);
        return Rotate_Left(a);
    }
    return a;
}

node smallest(node a)
{
    node key = a;
    while (key->left != NULL)
    {
        key = key->left;
    }
    return key;
}

node delete(node a, int value)
{
    if (a == NULL)
    {
        return a;
    }
    if (value < a->value)
    {
        a->left = delete(a->left, value);
    }
    else if (value > a->value)
    {
        a->right = delete(a->right, value);
    }
    else
    {
        if ((a->left == NULL) || (a->right == NULL))
        {
            node temp = a->left ? a->left : a->right;
            if (temp == NULL)
            {
                temp = a;
                a = NULL;
            }
            else
            {
                *a = *temp;
            }
            free(temp);
        }
        else
        {
            node temp = smallest(a->right);
            a->value = temp->value;
            a->right = delete(a->right, temp->value);
        }
    }
    if (a == NULL)
    {
        return a;
    }
    a->height = get_Max(get_Height(a->left), get_Height(a->right)) + 1;
    int balance = get_Balance(a);
    if (balance > 1 && get_Balance(a->left) >= 0)
    {
        return Rotate_Right(a);
    }
    if (balance > 1 && get_Balance(a->left) < 0)
    {
        a->left = Rotate_Left(a->left);
        return Rotate_Right(a);
    }
    if (balance < -1 && get_Balance(a->right) <= 0)
    {
        return Rotate_Left(a);
    }
    if (balance < -1 && get_Balance(a->right) > 0)
    {
        a->right = Rotate_Right(a->right);
        return Rotate_Left(a);
    }
    return a;
}

void print(node a)
{
    if (a == NULL)
    {
        return;
    }
    print(a->left);
    printf("%d ", a->value);
    print(a->right);
}

int main()
{
    node a = NULL;
    a = insert(a, 45);
    a = insert(a, 67);
    a = insert(a, 345);
    a = insert(a, 456);
    a = insert(a, 323);
    a = insert(a, 234);
    a = insert(a, 765);
    a = insert(a, 3);
    a = insert(a, 298);
    print(a);
    printf("\n");
    a = delete(a, 3);
    print(a);
    printf("\n");
    a = delete(a, 298);
    print(a);
    return 0;
}