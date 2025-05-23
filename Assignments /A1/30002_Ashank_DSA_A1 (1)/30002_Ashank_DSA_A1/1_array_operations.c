#include <stdio.h>

int array_insert(int* arr, int arr_len, int value, int index) {
    if (index < 0 || index >= arr_len) return -1;
    for (int i = arr_len - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    return 0;
}

int array_search(int* arr, int arr_len, int value) {
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int array_delete(int* arr, int arr_len, int value) {
    int index = array_search(arr, arr_len, value);
    if (index == -1) return -1;
    for (int i = index; i < arr_len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[arr_len - 1] = 0;
    return 0;
}

void array_display(int *arr, int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr_len, user_ip;
    printf("Enter size of Array:\n");
    scanf("%d", &arr_len);
    int arr[arr_len];
    printf("Enter %d elements:\n", arr_len);
    for (int i = 0; i < arr_len; i++) {
        scanf("%d", &arr[i]);
    }


    while (1) {
        printf("**********************************************************************\n");
        printf("MENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("**********************************************************************\n");

        printf("Enter your choice:\n");
        scanf("%d", &user_ip);

        switch (user_ip) {
            case 1: {
                int value, index;
                printf("Enter value to be inserted:\n");
                scanf("%d", &value);
                printf("Enter index to be inserted:\n");
                scanf("%d", &index);
                array_insert(arr, arr_len, value, index);
                printf("Array after insertion:\n");
                array_display(arr, arr_len);
                break;
            }
            case 2: {
                int value2;
                printf("Enter value to be deleted:\n");
                scanf("%d", &value2);
                array_delete(arr, arr_len, value2);
                printf("Array after deletion:\n");
                array_display(arr, arr_len);
                break;
            }
            case 3: {
                int value3;
                printf("Enter value to be searched:\n");
                scanf("%d", &value3);
                int found_index = array_search(arr, arr_len, value3);
                if (found_index != -1)
                    printf("Index Location: %d\n", found_index);
                else
                    printf("Value not found.\n");
                break;
            }
            case 4:
                array_display(arr, arr_len);
                break;
            case 5:
                printf("Exiting...\n");
                goto exit;
            default:
                printf("Invalid Input\n");
                break;
        }
    }

exit:
    return 0;
}
