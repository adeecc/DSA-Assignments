/**
 * Aditya Chopra
 * 2019A7PS0178H
 * DSA Lab Evaluation 21 APr, 2021 17:01
ID: 2019A7PS0178H
PASS: IjP5DA

Sample Testcase:

3
2 3 1
2 1 3

Output:

2 3
*/

#include <stdio.h>
#include <stdlib.h>

#define ll long long int

int n;

typedef struct Node_t {
    ll key;
    struct Node_t *l, *r;
} Node;

Node* createNode(ll key) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->l = node->r = NULL;

    return node;
}

int find(ll arr[n], int start, int end,
         ll key) {  // Implement Hashmap to speed up
    int i = start;
    for (; i <= end; ++i) {
        if (arr[i] == key) return i;
    }

    return -1;
}

Node* buildBTree(int start, int end, ll postOrder[n], ll inOrder[n],
                 int* postIdx) {
    if (start > end) return NULL;

    // printf("Post idx: %d\n", *postIdx);

    Node* root = createNode(postOrder[(*postIdx)]);
    (*postIdx)--;

    if (start == end) return root;

    int inIdx = find(inOrder, start, end, root->key);
    // printf("Inorder idx: %d\n", inIdx);

    root->r = buildBTree(inIdx + 1, end, postOrder, inOrder, postIdx);
    root->l = buildBTree(start, inIdx - 1, postOrder, inOrder, postIdx);

    return root;
}

void printPreOrderLeaves(Node* root) {
    if (root) {
        if (root->l == NULL && root->r == NULL) {
            printf("%lld ", root->key);
        }
        printPreOrderLeaves(root->l);
        printPreOrderLeaves(root->r);
    }
}

int main() {
    scanf("%d", &n);

    ll postorder[n], inorder[n];

    for (int i = 0; i < n; ++i) {
        scanf("%lld", postorder + i);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%lld", inorder + i);
    }

    int postIdx = n - 1;

    Node* root = buildBTree(0, n - 1, postorder, inorder, &postIdx);
    printPreOrderLeaves(root);
    return 0;
}
