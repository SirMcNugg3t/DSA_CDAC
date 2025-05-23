#include <stdio.h>
#include <stdlib.h>
#include "SLL_Implementation.h"

int main() {
    int num;
    printf("Enter number of elements : ");
    scanf("%d",&num);

    struct node *head = NULL;
    for (int i = 0; i < num; i++) {
        int x;
        printf("Enter %d element : ",i+1);
        scanf("%d",&x);
        head = push_node(head,x);
    }

    display(head);

    return 0;
}


//IMPLEMENTATION


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