#include <stdio.h>
#include <stdlib.h>

void Quick_Sort(int *a, int beginning, int ending)
{
    if (beginning >= ending)
        return;
    int pivot = a[ending];
    int i = beginning - 1;
    for (int j = beginning; j < ending; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[ending];
    a[ending] = temp;
    Quick_Sort(a, beginning, i);
    Quick_Sort(a, i + 2, ending);
}

int main()
{
    int n;
    printf("No. of elements: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Quick_Sort(a, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}