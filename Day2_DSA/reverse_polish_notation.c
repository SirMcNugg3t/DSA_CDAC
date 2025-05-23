#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

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
    A[++top] = item;
}


int pop() {
    if (IsEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return A[top--];
}

void display() {
    for (int i = 0; i <= top; i++) {
        switch (A[i]) {
            case '+': printf("%c ",A[i]); break;
            case '-': printf("%c ",A[i]); break;
            case '*': printf("%c ",A[i]); break;
            case '/': printf("%c ",A[i]); break;
            default: printf("%d ", A[i]); break;

        }}
    printf("\n");
}

bool IsFull() {
    return top == MAX_SIZE - 1;
}

bool IsEmpty() {
    return top == -1;
}

int postfix() {
    for (int i = 0; i <= top; i++) {
        if (A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/') {
            int op = A[i];
            int b = pop();
            int a = pop();

            switch (op) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        } else {
            push(A[i]);
        }
    }

    return pop();
}

int main(void) {
    push(10);
    display();
    push(6);
    push(4);
    display();
    push('+');
    display();
    push(4);
    push(9);
    push('*');
    push('+');
    push(10);
    push('-');
    push('*');
    display();

    int result = postfix();
    printf("Result: %d\n", result);

    return 0;
}
