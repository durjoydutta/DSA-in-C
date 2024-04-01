#include <stdio.h>
#include <stdlib.h>

int* mergeSortedList(int L1[], int L2[], int size)
{
    int *temp = malloc(2*size*sizeof(int));
    int tempIn = 0;
    int i = 0; int j = 0;
    while (i < size && j < size)
    {
        if (L1[i] < L2[j])
        {
            temp[tempIn++] = L1[i];
            i++;
        }
        if (L2[j] < L1[i])
        {
            temp[tempIn++] = L2[j];
            j++;
        }
    }
    while (i < size)
    {
        temp[tempIn++] = L1[i];
        i++;
    }
    while (j < size)
    {
        temp[tempIn++] = L2[j];
        j++;
    }

    return temp;
}

int main()
{
    int L1[] = {5,12,56,98,334};
    int L2[] = {7,15,34,52,107};
    int n = 10;
    int *res = mergeSortedList(L1, L2, n/2);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
    free(res);
    return 0;
}