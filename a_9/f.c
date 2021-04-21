#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 1001

typedef struct Node_t {
    ll key;
    struct Node_t* left;
    struct Node_t* right;
} Node;

Node* createNode(ll key) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* node, ll key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);

    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

void postOrderTraversal(Node* root, int n, Node* postOrder[n], int* top) {
    if (!root) return;

    postOrderTraversal(root->left, n, postOrder, top);
    postOrderTraversal(root->right, n, postOrder, top);
    postOrder[++(*top)] = root;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    ll temp;
    for (int i = 0; i < n; ++i) {
        scanf("%lld%*c", &temp);
        root = insert(root, temp);
    }

    Node* postOrder[n];
    int top = -1;

    postOrderTraversal(root, n, postOrder, &top);

    for (int i = 0; i < top; i++) {
        printf("%lld ", postOrder[i]->key);
    }

    printf("%lld", postOrder[top]->key);

    return 0;
}