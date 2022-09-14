// floating piong for loop stress test

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float a;
    for (i = 0; i < 100000000; i++)
    {
        a = 1.0;
        a = a + 1.0;
    }
    printf("a = %a", a);
    for (a = 0; i < 100000000; i++)
    {
        a = 1.0;
        a = a + 1.0;
        if (a == 0.0)
        {
            printf("a = %a\n", a);
        }
    }
    return 0;
}