#include <stdio.h>

// Function to find min and max using pairwise comparison
void findMinMax(int arr[], int n, int *min, int *max) {
    int i;

    // Handle edge case: Empty array
    if (n == 0) {
        *min = *max = -1;
        return;
    }

    // If n is odd, initialize min and max with the first element
    if (n % 2 != 0) {
        *min = *max = arr[0];
        i = 1; // Start from the second element
    } else {
        // If n is even, initialize min and max with the first two elements
        if (arr[0] < arr[1]) {
            *min = arr[0];
            *max = arr[1];
        } else {
            *min = arr[1];
            *max = arr[0];
        }
        i = 2; // Start from the third element
    }

    // Process elements in pairs
    while (i < n - 1) {
        if (arr[i] < arr[i + 1]) {
            if (arr[i] < *min) *min = arr[i];
            if (arr[i + 1] > *max) *max = arr[i + 1];
        } else {
            if (arr[i + 1] < *min) *min = arr[i + 1];
            if (arr[i] > *max) *max = arr[i];
        }
        i += 2; // Move to the next pair
    }
}

int main() {
    int arr[] = {3, 1, 7, 9, 2, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, n, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
