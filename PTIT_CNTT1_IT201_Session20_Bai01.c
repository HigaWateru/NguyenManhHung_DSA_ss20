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
void printTree(Node *root) {
    printf("data: %d\nleft->NULL\nright->NULL", root->data);
}
int main() {
    int val;
    scanf("%d", &val);
    Node *root = createNode(val);
    printTree(root);
}