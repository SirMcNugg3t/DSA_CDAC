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
    head = push_node(head, 40);
    display(head);
    head = pop_node(head);
    display(head);
    head = insert_node(head,23,0);
    display(head);
    head = insert_node(head,73,2);
    display(head);
    return 0;
}

//IMPLEMENTATION

/*void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d (%d)-->  ", temp->data,temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}*/