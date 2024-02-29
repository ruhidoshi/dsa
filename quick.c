Quick
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];  // Select the first element as the pivot
    int start = lb;   // Left boundary of the region of elements smaller than or equal to the pivot
    int end = ub;         // Right boundary of the region of elements greater than the pivot
    
    // Loop until the start index is less than or equal to the end index
    while (start <= end) {
        // Find the first element from the left that is greater than the pivot
        while (arr[start] <= pivot)
            start++;
        
        // Find the first element from the right that is smaller than or equal to the pivot
        while (arr[end] >= pivot)
            end--;
        
        // Swap the elements at the start and end positions
        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    
    // Swap the pivot (arr[lb]) with the element at the end position (arr[end])
    swap(&arr[lb], &arr[end]);
    
    // Return the index of the pivot after partitioning
    return end;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        // Partition the array
        int pi = partition(arr, lb, ub);
        
        // Sort the sub-arrays
        quickSort(arr, lb, pi - 1);
        quickSort(arr, pi + 1, ub);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
