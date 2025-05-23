#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    bool swapped = true;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1])  // change symbol for ascending - descending
                {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;

    }
}

int main(void) {
    int arr[] = {5 ,56 ,7,76,3,9,22,43};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,n);
    printArray(arr, n);
    return 0;
}