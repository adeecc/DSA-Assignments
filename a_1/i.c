#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    uint32_t data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(uint32_t data) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->next = NULL;
    node->data = data;

    return node;
}

void push(Node** head_ref, uint32_t data) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}

void append(Node** head_ref, uint32_t data) {
    Node* node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;

    node->data = data;
    node->next = NULL;

    while (last->next)
    {
        last = last->next;
    }

    last->next = node;
}

void reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = *head_ref;

    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    (*head_ref) = prev;
}

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    uint32_t n = 0;

    Node* head = NULL;

    while (1) {
        scanf("%d%*c", &n);

        if (n == -1) break;

        if (head)
            append(&head, n);

        else {
            head = createNode(n);
        }
    };

    reverse(&head);
    print(head);

    return 0;
}