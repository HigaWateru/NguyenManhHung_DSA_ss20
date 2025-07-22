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
int maxTree(Node *root) {
    if (root == NULL) return 0;
    int max = root->data;
    int left = maxTree(root->left);
    int right = maxTree(root->right);
    if (left > max) max = left;
    if (right > max) max = right;
    return max;
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(6);
    root->left->right = createNode(5);
    printf("max value: %d\n", maxTree(root));
    return 0;
}