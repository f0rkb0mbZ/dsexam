#include <stdio.h>
#include <stdbool.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void bubblesort(int *arr, int size)
{
    bool isSorted = false;
    int lastUnsorted = size - 1;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < lastUnsorted; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }
        lastUnsorted--;
    }
}

int main()
{
    int size;
    int arr[] = {2, 5, 8, 7, 1, 3, 4, 6, 8, 0, 2, 4, 3};
    size = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, size);
    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}