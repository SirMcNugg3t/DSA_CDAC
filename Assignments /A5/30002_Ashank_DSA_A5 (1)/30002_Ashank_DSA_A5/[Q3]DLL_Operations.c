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
struct node* insert(struct node *head, int value, int pos) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = value;

    if (pos == 0) {
        new->next = head;
        new->prev = NULL;
        if (head != NULL)
            head->prev = new;
        return new;
    }

    struct node *temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return head;

    new->next = temp->next;
    new->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new;

    temp->next = new;
    return head;
}
struct node* delete(struct node *head, int pos) {
    for (int i = 0; i < pos; i++) {
        struct node *temp = head;
        if (temp == NULL) {
            return head;
        }
        else {
            for (int i; i < pos-1; i++) {
                temp = temp->next;
            }
            temp = temp -> next -> next;
            temp -> next -> prev = temp;
        }
    }}
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
    head = insert(head , 546, 2);
    display(head);
    head = delete(head, 2);
    display(head);

    return 0;
}
