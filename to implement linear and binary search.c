#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1; 
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the number to search: ");
    scanf("%d", &key);

    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1)
        printf("Linear Search: Element found at index %d\n", linearResult);
    else
        printf("Linear Search: Element not found\n");

    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1)
        printf("Binary Search: Element found at index %d\n", binaryResult);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
