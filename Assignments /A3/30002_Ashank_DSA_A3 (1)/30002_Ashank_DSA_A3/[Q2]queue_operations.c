#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int F = -1 ,R = -1,A[MAX_SIZE];

bool isFull() {
    return R == MAX_SIZE - 1;
}
bool isEmpty() {
    return R == -1 && F == -1;
}

void enqueue(int item) {
    if(isFull()){
        printf("Queue is full\n");
        return;
    }

    else if (isEmpty()) {
        F = R = 0;
        A[R] = item;
        printf("Enqueued %d\n", item);
        return;
    }
    printf("Enqueued %d\n", item);
    A[++R] = item;
    return;
}
int dequeue() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    else if(R == F) {
        int ans = A[R];
        printf("Dequeued %d\n", ans);
        R = F = -1 ;
        return ans;
    }
    printf("Dequeued %d\n", A[F]);
    return A[F++];
}
void display() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("F = %d\tR = %d\n", F,R);
    for(int i = F; i <= R; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {

    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
            switch (choice) {
                case 1:
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    printf("\n");
                    enqueue(value);
                    display();
                    break;

                case 2:
                    dequeue();
                    display();
                    break;

                case 3:
                    display();
                    break;

                case 4:
                    printf("%d\n",A[F]);
                    break;

                case 5:
                    printf("Exiting...\n");
                    return 0;

                default:
                    printf("Invalid choice! Try again.\n");
                    break;

        }

    }

    return 0;
}