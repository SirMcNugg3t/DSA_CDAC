struct node {
    int data;
    struct node *next;
};

struct node *push_node(struct node *head, int data);
struct node *pop_node(struct node *head);
int length(struct node *head);
struct node *insert_node(struct node *head, int data, int pos);
void display(struct node *head);
int find(struct node *head, int data);
struct node *enqueue(struct node *head, int data);
struct node *dequeue(struct node *head);