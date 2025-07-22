#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct Queue {
    Node* data[100];
    int front;
    int rear;
} Queue;
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}
void enqueue(Queue *q, Node *node) {
    q->data[++q->rear] = node;
}
void insert(Node *root, int val) {
    if (root == NULL) return;
    Queue q;
    init(&q);
    enqueue(&q, root);
    while (q.front <= q.rear) {
        Node *current = q.data[q.front++];
        if (current->left == NULL) {
            current->left = createNode(val);
            break;
        }
        else enqueue(&q, current->left);
        if (current->right == NULL) {
            current->right = createNode(val);
            break;
        }
        else enqueue(&q, current->right);
    }
}
void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int val; scanf("%d", &val);
    insert(root, val);
    preOrder(root);
    return 0;
}