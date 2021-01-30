#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    uint32_t data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;

    node->next = (*head_ref);
    node->prev = NULL;

    if ((*head_ref) != NULL) (*head_ref)->prev = node;

    (*head_ref) = node;
}

void append(struct Node** head_ref, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    node->data = data;

    node->next = NULL;

    if ((*head_ref) == NULL) {
        node->prev = NULL;
        *head_ref = node;
        return;
    }

    while (last->next != NULL) last = last->next;

    last->next = node;
    node->prev = last;
}

void traverse(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }

    printf("\n");
}

void LS(struct Node** head_ref, int lsb) {
    struct Node* last = *head_ref;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    while (last->next != NULL) last = last->next;

    node->data = lsb;
    node->next = NULL;

    last->next = node;
    node->prev = last;

    (*head_ref) = (*head_ref)->next;
    (*head_ref)->prev = NULL;
}

void RS(struct Node** head_ref, int msb) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = msb;

    node->next = (*head_ref);
    (*head_ref)->prev = node;

    node->prev = NULL;
    (*head_ref) = node;

    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        return;
    }

    struct Node* second_last = *head_ref;

    while (second_last->next->next != NULL) second_last = second_last->next;

    free(second_last->next);
    second_last->next = NULL;
}

void LR(struct Node** head_ref) {
    int data = (*head_ref)->data;
    LS(head_ref, data);
}

void RR(struct Node** head_ref) {
    struct Node* last = *head_ref;

    while (last->next != NULL) last = last->next;

    RS(head_ref, last->data);
}

void INC(struct Node** head_ref) {
    uint32_t carry = 1, a, b;

    struct Node* last = *head_ref;
    while (last->next != NULL) last = last->next;

    while (1) {
        a = last->data;
        b = carry;

        carry = a & b;
        last->data = a ^ b;

        if (last->prev == NULL) break;
        last = last->prev;
    }

    (*head_ref) = last;
}

void DEC(struct Node** head_ref) {

    uint32_t carry = 0, a, b = 1, Cin;

    struct Node* last = *head_ref;
    while (last->next != NULL) last = last->next;

    while (1) {
        a = last->data;
        Cin = carry;

        carry = a & b | a & Cin | b & Cin;
        last->data = a ^ b ^ Cin;

        if (last->prev == NULL) break;
        last = last->prev;
    }

    (*head_ref) = last;
}

int main() {
    int len = 0,  n;
    char c, instruction;

    struct Node* head = NULL;

    while (1) {
        scanf("%c", &c);

        if (c == '\n') break;

        append(&head, c - '0');
        len++;
    }

    scanf("%d%*c", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%c", &instruction);

        if (instruction == 'L') {
            scanf("%c%*c", &instruction);

            if (instruction == 'S') 
                LS(&head, 0);
             else if (instruction == 'R') 
                LR(&head);
            
        } else if (instruction == 'R') {
            scanf("%c%*c", &instruction);
            
            if (instruction == 'S') 
                RS(&head, 0);
             else if (instruction == 'R') 
                RR(&head);

        } else if (instruction == 'I') {
            scanf("%*c%*c%*c");
            INC(&head);
        } else if (instruction == 'D') {
            scanf("%*c%*c%*c");
            DEC(&head);
        }
    }

    traverse(head);    

    return 0;
}