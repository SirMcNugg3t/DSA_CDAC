#include <stdio.h>
#include <stdlib.h>

void sequential_search(int arr[],int length, int key) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            printf("%d [%d]", arr[i],i);
            return ;
        }
    }
    printf("Not found\n");
    return ;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    sequential_search(arr, length, 5);
    return 0;
}