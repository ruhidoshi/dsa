Merge sort 
#include <stdio.h>

void merge(int a[], int lb, int mid, int ub)
{
    int i, j, k, b[20];
    i = lb;
    j = mid + 1;
    k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

void mergesort(int arr[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int size, array[10], i;
    printf("ENTER SIZE OF THE ARRAY: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT: ");
        scanf("%d", &array[i]);
    }
    mergesort(array, 0, size - 1);
    printf("SORTED ARRAY IS: ");
    printArr(array, size);
    return 0;
}
