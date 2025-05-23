#include <stdio.h>

void swap(int * a, int * b ){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;

}
int partition(int arr[],int l,int r){
    int pivot = arr[r];
    while(l< r){
        while(arr[l] < pivot ){
            l++;
        }
        while(arr[r] > pivot){
            r--;
        }

        if (l < r){
            swap(&arr[l],&arr[r]);
        }

    }
    swap(&arr[r],&pivot);
    return l;
}
void quickSort(int arr[],int l,int r){
    if (l>r) return ;
    int m = partition(arr,l,r);
    quickSort(arr,l,m-1);
    quickSort(arr,m+1,r);
    return;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 1,2,4,99,56 ,7,76,3,9,22,43};

    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printArray(arr,n);

    return 0;
}
