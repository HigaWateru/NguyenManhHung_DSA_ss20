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
int findLevel(Node *root, int val) {
    if (root == NULL) return -1;
    int level = 0;
    Queue q;
    init(&q);
    enqueue(&q, root);
    while (q.front <= q.rear) {
        int size = q.rear - q.front + 1;
        for (int i = 0; i < size; i++) {
            Node *current = q.data[q.front++];
            if (current->data == val) return level;
            if (current->left != NULL) enqueue(&q, current->left);
            if (current->right != NULL) enqueue(&q, current->right);
        }
        level++;
    }
    return -1;
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(6);
    root->left->right = createNode(5);
    int val; scanf("%d", &val);
    int level = findLevel(root, val);
    if (level == -1) printf("Gia tri khong ton tai");
    else printf("Node level: %d", level);
    return 0;
}