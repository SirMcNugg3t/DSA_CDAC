#include <stdio.h>

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

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min =  arr[j];
                swap(&arr[j], &arr[i]);
            }
        }
    }
}


int main(void) {
    int arr[] = {6 ,56 ,7,76,3343,10,22,43};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr,n);
    printArray(arr, n);
    return 0;
}