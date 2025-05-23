#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* push(struct node *head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }

    return temp;
}
struct node* pop(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);


    display(head);
    head = pop(head);
    display(head);

    return 0;
}
