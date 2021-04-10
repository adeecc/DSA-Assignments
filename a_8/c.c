#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 1001

typedef struct Node_t {
    int key;
    struct Node_t* left;
    struct Node_t* right;
} Node;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* createTree(int n, int arr[n]) {
    Node* treeArr[n];

    for (int i = 0; i < n; i++) {
        treeArr[i] = createNode(arr[i]);
    }

    int u, v;
    char dir;

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %c%*c", &u, &v, &dir);

        switch (dir) {
            case 'L':
                treeArr[u]->left = treeArr[v];
                break;
            case 'R':
                treeArr[u]->right = treeArr[v];
                break;

            default:
                break;
        }
    }

    return treeArr[0];
}

void printTree(Node* node) {
    if (node) {
        printf("%d ", node->key);
        printTree(node->left);
        printTree(node->right);
        printf("\n");
    }
}

void inOrder(Node* root, int n) {
    if (!root) return;

    Node* stack[5];
    int top = -1;

    Node* current = root;

    while (current || top > -1) {
        while (current) {
            stack[++top] = current;
            current = current->left; 
        }

        current = stack[top--];
        printf("%d ", current->key);
        current = current->right;
    } 
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    Node* root = createTree(n, arr);
    
    inOrder(root, n);

    return 0;
}