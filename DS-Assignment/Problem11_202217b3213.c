#include <stdio.h>
#include <stdlib.h>  // For malloc and free functions

/* Function to perform a linear search on the array */
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

int main()
{
    int n;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Get the array elements from the user
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Get the target value from the user
    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Call the linear search function
    int result = linearSearch(arr, n, target);

    // Print the result of the search
    if (result == -1)
    {
        printf("Element %d not found in the array.\n", target);
    }
    else
    {
        printf("Element %d found at index: %d\n", target, result);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}
