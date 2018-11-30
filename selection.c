#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void selectSort(int *arr, int size)
{
    int i, j, min_index;
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_index])
                min_index=j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int main()
{
    int size;
    int arr[] = {2, 5, 8, 7, 1, 3, 4, 6, 8, 0, 2, 4, 3};
    size = sizeof(arr) / sizeof(arr[0]);
    selectSort(arr, size);
    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}