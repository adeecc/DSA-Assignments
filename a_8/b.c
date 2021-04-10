#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ll long long int
#define ull unsigned long long int

#define N 1001
#define MOD (ll)(1e9 + 7)

// ll abs(ll a) {
//     return a > 0 ? a : -a;
// }

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

void inOrderTraversal(Node* root, int n, Node* inOrder[n], int* top) {
    if (!root) return;

    inOrderTraversal(root->left, n, inOrder, top);
    inOrder[++(*top)] = root;
    inOrderTraversal(root->right, n, inOrder, top);
}

void preOrderTraversal(Node* root, int n, Node* preOrder[n], int* top) {
    if (!root) return;

    preOrder[++(*top)] = root;
    preOrderTraversal(root->left, n, preOrder, top);
    preOrderTraversal(root->right, n, preOrder, top);
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

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    Node* root = createTree(n, arr);

    Node *A[n], *B[n], *C[n];

    int top;

    top = -1;
    preOrderTraversal(root, n, A, &top);

    top = -1;
    postOrderTraversal(root, n, B, &top);

    top = -1;
    inOrderTraversal(root, n, C, &top);

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        sum = (sum + (abs(A[i]->key - B[i]->key) * C[i]->key)) % MOD;
    }
    printf("%lld", sum);

    return 0;
}