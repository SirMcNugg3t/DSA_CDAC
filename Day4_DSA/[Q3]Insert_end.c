#include <stdio.h>
#include <stdlib.h>
#include "SLL_Implementation.h"

int main() {
    struct node *head = NULL;
    head = push_node(head, 10);
    display(head);
    head = push_node(head, 20);
    display(head);
    head = push_node(head, 30);
    display(head);
    return 0;
}

// IMPLEMENTATION

/*struct node *push_node(struct node *head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return head;

    }
    struct node *temp1 = head;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}*/