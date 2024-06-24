#include <stdio.h>

void countOccurrences(int arr[], int size) {
    // Create an array to store frequencies
    int freq[size];
    // Initialize all frequencies to -1
    for (int i = 0; i < size; i++) {
        freq[i] = -1;
    }

    // Traverse through array elements and count frequencies
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                // To avoid counting same element again
                freq[j] = 0;
            }
        }

        // If frequency of current element is not counted
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    // Print the frequency of each element
    printf("Element : Frequency\n");
    for (int i = 0; i < size; i++) {
        if (freq[i] != 0) {
            printf("%d : %d\n", arr[i], freq[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 2, 3, 4, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countOccurrences(arr, size);

    return 0;
}
