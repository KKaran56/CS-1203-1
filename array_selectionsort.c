#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("No. of elements: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[smallest])
                smallest = j;
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}