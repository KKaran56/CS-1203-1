#include <stdio.h>
#include <stdlib.h>

int main()
{
    // pointers
    int x = 33;
    int *y = &x;
    printf("x = %d", x);
    printf("y = %p", y);
    printf("*y = %d", *y);

    // malloc
    int *p;
    int i;
    p = (int *)malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++)
    {
        p[i] = i;
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }

    // realloc
    p = (int *)realloc(p, 10 * sizeof(int));
    for (i = 5; i < 10; i++)
    {
        p[i] = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }

    // free memory
    free(p);

    return 0;
}