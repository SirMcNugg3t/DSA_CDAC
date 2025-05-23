#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100
int A[MAX_SIZE];
int top = -1;

bool IsFull();
bool IsEmpty();

void push(int item) {
    if (IsFull()) {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    A[top] = item;
};
int pop() {
    if (IsEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    top = top - 1;
    return A[top-1];
}
void display() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return;
}
bool IsFull() {
    if (top == MAX_SIZE - 1) return true;
    return false;
}
bool IsEmpty() {
    if (top == -1) return true;
    return false;
}

int main(void) {
    int option, item;
    do {
        printf("1. Push\n2. Pop\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                return 0;

        }
    }while(option != 3);

    return 0;
}