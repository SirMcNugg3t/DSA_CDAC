#include <stdio.h>
#include <stdlib.h>
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
                if (arr[j] < arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;

    }
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
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

    }

}


int partition(int a[],int l,int r){
    int pivot = a[r];
    while(l<r){
        while(a[l]<pivot)l++;
        while(a[r]>pivot)r--;
        if(l<r)swap(&a[l],&a[r]);
    }
    swap(&a[l],&pivot);
    return l;

}

void quickSort(int arr[],int l, int r){
    if (l >= r) return;
    int mid = partition(arr,l,r);
    quickSort(arr,l,mid-1);
    quickSort(arr,mid+1,r);
}


void merge(int a[],int l,int m, int r)
    {      
        int b[r-l+1];
        int i = l;
        int j = m+1;
        int k = 0;

        while (i <= m && j <=r){
            if (a[i]<=a[j])b[k++]=a[i++];
            else b[k++] = a[j++];
        }

        while(i <= m){
            b[k++] = a[i++];
        }

        while(j <= r){
            b[k++] = a[j++];
        }

        int size = sizeof(b)/sizeof(b[0]);
        for(int i=0; i < size;i++){
            a[l+i]  = b[i];  
        }


}
void mergeSort(int arr[],int l,int r){
    if (l>=r)return;
    int m = l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    return ;
    

}
int main(void) {
    int arr[] = {5, 1,2,4,99,56 ,7,76,3,9,22,43};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    printArray(arr, n);

    return 0;
}