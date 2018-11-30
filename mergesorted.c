#include <stdio.h>

void mergearrays(int *arr1, int *arr2, int size1, int size2, int *arr3)
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    //printf("%d\t%d\n", i, j);
    while (i < size1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < size2)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];
    mergearrays(arr1, arr2, n1, n2, arr3);
    printf("Array after merging:\n");

    for (int i = 0; i < n1 + n2; i++)
        printf("%d\t", arr3[i]);
    return 0;
}