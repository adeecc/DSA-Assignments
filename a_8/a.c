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

void swapArray(Node* a[N], Node* b[N]) {
    for (int i = 0; i < N; i++) {
        Node* temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

// void swapArray(int **a, int **b) {
//     int* temp = *a;
//     *a = *b;
//     *b = temp;
// }

void traverse(Node* node) {
    if (!node) return;

    Node* currentLevel[N];
    int currentLevelTop = -1;

    Node* nextLevel[N];
    int nextLevelTop = -1;

    currentLevel[++currentLevelTop] = node;

    int leftOrRight = TRUE;

    while (currentLevelTop > -1) {
        Node* temp = currentLevel[currentLevelTop--];

        if (temp) {
            printf("%d ", temp->key);

            if (leftOrRight) {
                if (temp->left) nextLevel[++nextLevelTop] = temp->left;
                if (temp->right) nextLevel[++nextLevelTop] = temp->right;
            }

            else {
                if (temp->right) nextLevel[++nextLevelTop] = temp->right;
                if (temp->left) nextLevel[++nextLevelTop] = temp->left;
            }
        }

        if (currentLevelTop == -1) {
            leftOrRight = !leftOrRight;

            swapArray(currentLevel, nextLevel);

            int temp = currentLevelTop;
            currentLevelTop = nextLevelTop;
            nextLevelTop = temp;
        }
    }
}

void printTree(Node *node) {
    if (node) {
        printf("%d ", node->key);
        printTree(node->left);
        printTree(node->right);
        printf("\n");
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
    // printf("Tree:\n");

    // printTree(root);
    // printf("\n");

    traverse(root);

    return 0;
}