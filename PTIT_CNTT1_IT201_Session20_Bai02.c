#include <stdio.h>
#include <stdlib.h>

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
typedef struct queueNode {
    Node *treeNode;
    struct queueNode *next;
} queueNode;
typedef struct Queue {
    queueNode *front;
    queueNode *rear;
} Queue;
void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}
void enqueue(Queue* q, Node* treeNode) {
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    queueNode *temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}
void levelOrder(Node *root) {
    Queue q;
    init(&q);
    enqueue(&q, root);
    while (q.front != NULL) {
        Node *treeNode = dequeue(&q);
        printf("%d ", treeNode->data);
        if (treeNode->left != NULL) enqueue(&q, treeNode->left);
        if (treeNode->right != NULL) enqueue(&q, treeNode->right);
    }
}
void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printf("Duyet truoc: ");
    preOrder(root);
    printf("\nDuyet sau: ");
    postOrder(root);
    printf("\nDuyet giua: ");
    inOrder(root);
    printf("\nDuyet theo level:");
    levelOrder(root);
}