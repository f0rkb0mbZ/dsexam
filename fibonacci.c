#include <stdio.h>
#include <stdlib.h>
void printarr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int arr_size;
    int *fibarr;
    printf("Enter the fibonacci array size: ");
    scanf("%d", &arr_size);
    fibarr = (int *)malloc(sizeof(int) * arr_size);

    int a = 0, b = 1;
    fibarr[0] = a;
    fibarr[1] = b;
    for (int i = 2; i < arr_size; i++)
    {
        fibarr[i] = fibarr[i - 1] + fibarr[i - 2];
    }

    printf("The fibonacci array is:\n");
    printarr(fibarr, arr_size);
    return 0;
}