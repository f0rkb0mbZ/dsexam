#include <stdio.h>

void insertSort(int *arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int size;
    int arr[] = {2, 5, 8, 7, 1, 3, 4, 6, 8, 0, 2, 4, 3};
    size = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr, size);
    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}