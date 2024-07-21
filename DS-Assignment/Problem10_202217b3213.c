#include <stdio.h>
#include <stdlib.h> // For malloc and free functions

/* Function to merge two subarrays of a[] */
void merge(int a[], int beg, int mid, int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    // Create temporary arrays
    int *LeftArray = (int *)malloc(n1 * sizeof(int));
    int *RightArray = (int *)malloc(n2 * sizeof(int));

    if (LeftArray == NULL || RightArray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    /* Copy data to temp arrays */
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    int i = 0;  // Initial index of first sub-array
    int j = 0;  // Initial index of second sub-array
    int k = beg; // Initial index of merged sub-array

    // Merge the temp arrays back into a[]
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of LeftArray[], if any
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of RightArray[], if any
    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }

    // Free allocated memory for temporary arrays
    free(LeftArray);
    free(RightArray);
}

/* Function to perform merge sort */
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);      // Sort the first half
        mergeSort(a, mid + 1, end);  // Sort the second half
        merge(a, beg, mid, end);    // Merge the two halves
    }
}

/* Function to print the array */
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {12, 31, 25, 8, 32, 17, 40, 42};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are:\n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);  // Sort the array

    printf("After sorting array elements are:\n");
    printArray(a, n);

    return 0;
}
