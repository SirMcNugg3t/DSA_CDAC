#include <stdio.h>
#include <stdlib.h>

void binarySearch(int arr[], int start_index, int size, int key) {
    int mid = (start_index + size-1) / 2;
    if (arr[mid] == key) {
        printf("%d [%d]\n", key , mid);
        return;
    }
    else if (arr[mid] > key) {
        binarySearch(arr, start_index, mid - 1, key);

    }
    else {
        binarySearch(arr, mid + 1, size, key);
    }
    return;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    binarySearch(arr, 0, size, 10);
    return 0;
}

void iterative_binary_search(int arr[], int start_index, int size, int key) {
    int mid = (start_index + size-1) / 2;
    if (arr[mid] == key) {
        printf("%d [%d]\n", key, mid);
    }
    else if (arr[mid] > key) {
        iterative_binary_search(arr, start_index, mid - 1, key);
    }
}