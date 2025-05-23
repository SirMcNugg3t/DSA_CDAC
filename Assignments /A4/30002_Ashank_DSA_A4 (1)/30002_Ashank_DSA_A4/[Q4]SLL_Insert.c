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
    printf("--------INSERT----------\n");
    printf("Enter number to insert: ");
    scanf("%d",&num);
    int pos;
    printf("Enter position : ");
    scanf("%d",&pos);
    printf("\n");
    head = insert_node(head,num,pos-1);
    display(head);
    return 0;
}

//IMPLEMENTATION

/*struct node *insert_node(struct node *head, int data , int pos) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    struct node *temp1 = head;
    if (pos < 0 || pos > length(head)) {
        printf("Invalid position\n");
        return new_node;

    }
    if (pos == 0) {
        new_node->next = head;
        return new_node;
    }
    for (int i = 0; i < pos-1; i++) {
        temp1 = temp1->next;
    }
    new_node->next = temp1->next;
    temp1->next = new_node;
    return head;
}*/