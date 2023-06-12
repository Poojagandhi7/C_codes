#include <stdio.h>
#include <conio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int i, j, pivot;
    pivot = arr[high];
    i = (low - 1);
    j = low;
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int Arr[], int low, int high)
{
    if (low < high)
    {
        int v;
        v = partition(Arr, low, high);
        quicksort(Arr, low, v - 1);
        quicksort(Arr, v + 1, high);
    }
}

int main()
{
    int i, n, arr[100];
    printf("enter number of element:");
    scanf("%d", &n);
    printf("enter element:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}
