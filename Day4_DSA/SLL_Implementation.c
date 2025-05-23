#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *push_node(struct node *head, int data) {
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
}
struct node *pop_node(struct node *head) {
    if (head == NULL) {
        printf("Empty list\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    int n =0;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;

}
int length(struct node *head) {
    if (head == NULL) {
        return 0;
    }
    struct node *temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}
struct node *insert_node(struct node *head, int data , int pos) {
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
}
void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d (%d)-->  ", temp->data,temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}
int find(struct node *head, int data) {
    struct node *temp = head;
    int count = 0;
    while (temp->next!= NULL) {

        if (temp->data == data) {
            return count;
        }
        count++;
        temp = temp->next;

    }
    return -1;
}
struct node *enqueue(struct node *head, int data) {
    head = insert_node(head, data, 0);
    return head;
}
struct node *dequeue(struct node *head) {
    head = pop_node(head);
    return head;
}


/*int main() {
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
    printf("%d\n", find(head, 20));
    head = enqueue(head, 99);
    display(head);
    head = dequeue(head);
    display(head);

    return 0;
}*/