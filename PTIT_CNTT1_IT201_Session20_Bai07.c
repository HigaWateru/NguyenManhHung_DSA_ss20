#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, Node* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}
void deleteNode(Node** root, int value) {
    if (*root == NULL) {
        printf("Cay rong.\n");
        return;
    }
    Queue* q = createQueue();
    enqueue(q, *root);
    Node* target = NULL;
    Node* current = NULL;
    Node* parent = NULL;
    while (!isEmpty(q)) {
        current = dequeue(q);
        if (current->data == value)target = current;
        if (current->left) {
            parent = current;
            enqueue(q, current->left);
        }
        if (current->right) {
            parent = current;
            enqueue(q, current->right);
        }
    }
    if (target == NULL) return;
    int x = current->data;
    target->data = x;
    if (parent != NULL) {
        if (parent->right == current) {
            free(parent->right);
            parent->right = NULL;
        }
        else if (parent->left == current) {
            free(parent->left);
            parent->left = NULL;
        }
    }
    else {
        free(*root);
        *root = NULL;
    }
    free(q);
}
void levelOrder(Node* root) {
    if (!root) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* node = dequeue(q);
        printf("%d ", node->data);
        if (node->left) enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
}
int val;
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->right = createNode(6);
    levelOrder(root);
    printf("\n");
    scanf("%d", &val);
    deleteNode(&root, val);
    levelOrder(root);
    return 0;
}