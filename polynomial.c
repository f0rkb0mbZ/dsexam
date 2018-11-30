#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void sum(int *pol1, int *pol2, int *pol3, int ord1, int ord2)
{
    int ord3 = max(ord1, ord2);


    for (int i = 0; i < ord1; i++)
    {
        pol3[i] = pol1[i];
    }

    for (int i = 0; i < ord2; i++)
    {
        pol3[i] = pol3[i] + pol2[i];
    }

    // return pol3;
}

void printpolynom(int *poly, int ord)
{
    for (int i = 0; i < ord; i++)
    {
        printf("%d", poly[i]);
        if (i != 0)
            printf("x^%d", i);
        if (i != ord - 1)
            printf(" + ");
    }
}

int main()
{
    int A[] = {5, 0, 10, 6};

    // The following array represents polynomial 1 + 2x + 4x^2
    int B[] = {1, 2, 4};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    int sumpoly[max(m,n)];
    printf("\nFirst polynomial is \n");
    printpolynom(A, m);
    printf("\nSecond polynomial is \n");
    printpolynom(B, n);

    sum(A, B, sumpoly, m, n);
    int size = max(m, n);

    printf("\nsum polynomial is \n");
    printpolynom(sumpoly, size);
    return 0;
}