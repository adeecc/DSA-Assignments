#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define N (int)1e5

typedef struct Node_t {
    ll key;
    struct Node_t *left, *right;
} Node;

Node *createNode(ll key) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->left = node->right = NULL;

    return node;
}

Node *insert(Node *root, ll key) {
    if (!root) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void printBST(Node *root) {
    if (root) {
        printBST(root->left);
        printf("%lld ", root->key);
        printBST(root->right);
        printf("\n");
    }
}

int main() {
    ll arr[] = {5, 3, 4, 5, 9, 6, 2, 4, 5, 7, 3, 5};
    int n = sizeof arr / sizeof(ll);

    Node *BST = NULL;

    for (int i = 0; i < n; i++) {
        BST = insert(BST, arr[i]);
    }

    printBST(BST);

    return 0;
}