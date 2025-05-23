#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insert_last_node(struct node *head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if (head == NULL) {
        temp->next = temp;
        return temp;
    }
    struct node *curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return head;
}

struct node *remove_last_node(struct node *head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct node *curr = head;
    while (curr->next->next != head) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = head;
    return head;
}

int length(struct node *head) {
    if (head == NULL) return 0;
    int count = 1;
    struct node *curr = head->next;
    while (curr != head) {
        count++;
        curr = curr->next;
    }
    return count;
}

struct node *insert_node(struct node *head, int data , int pos) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (pos < 0 || pos > length(head)) return head;
    if (pos == 0) {
        if (head == NULL) {
            new_node->next = new_node;
            return new_node;
        }
        struct node *curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        new_node->next = head;
        curr->next = new_node;
        return new_node;
    }
    struct node *curr = head;
    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    struct node *temp = head;
    do {
        printf("%d (%p)-->  ", temp->data, (void*)temp->next);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}



int main() {
    struct node *head = NULL;
    head = insert_last_node(head, 10);
    display(head);
    head = insert_last_node(head, 20);
    display(head);
    head = insert_last_node(head, 30);
    display(head);
    head = insert_last_node(head, 40);
    display(head);
    head = remove_last_node(head);
    display(head);
    head = insert_node(head, 23, 0);
    display(head);
    head = insert_node(head, 73, 2);
    display(head);

    return 0;
}