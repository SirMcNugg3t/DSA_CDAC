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

int merge(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;
    int b[r - l + 1];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++; k++;
        } else {
            b[k] = arr[j];
            j++; k++;
        }
    }

    if (i > m) {
        while (j <= r) {
            b[k] = arr[j]; j++; k++;
        }
    } else {
        while (i <= m) {
            b[k] = arr[i]; i++; k++;
        }
    }

    for (int x = 0; x < k; x++) {
        arr[l + x] = b[x];
    }

    return 0;
}

int mergeSort(int arr[], int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
    return 0;
}

int main(void) {
    int arr[] = {5 ,56 ,7,76,3,9,22,43};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}