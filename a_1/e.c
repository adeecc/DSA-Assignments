#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    uint32_t data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int data ) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
 
    node->data = data; 
 
    node->next = (*head_ref); 
    node->prev = NULL; 
 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = node; 
 
    (*head_ref) = node;
}

void append(struct Node** head_ref, int data)
{

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; 
 
    
    node->data = data;

    node->next = NULL;
 
    if ((*head_ref) == NULL) {
        node->prev = NULL;
        *head_ref = node;
        return;
    }
 
    while (last->next != NULL)
        last = last->next;
 
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

    while(last->next != NULL)
        last = last->next;

    node->data = lsb;
    node->next = NULL;

    last->next = node;
    node->prev = last;

    (*head_ref) = (*head_ref)->next;
}

void RS(struct Node** head_ref, int msb) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = msb;

    node->next = (*head_ref);
    node->prev = NULL;

    (*head_ref) = node;

    struct Node* second_last = *head_ref;

    while (second_last->next->next != NULL) 
        second_last = second_last->next;
    
    free(second_last->next);
    second_last->next = NULL;

}

void LR(struct Node** head_ref) {
    int data = (*head_ref)->data;
    LS(head_ref, data);
}

void RR(struct Node** head_ref) {
    struct Node* last = *head_ref;

    while(last->next != NULL)
        last = last->next;

    RS(head_ref, last->data);
}

void INC(struct Node** head_ref) {
    uint32_t carry = 0, a, b;

    struct Node* last = *head_ref;
    while(last->next != NULL)
        last = last->next;


    carry = last->data;
    last->data = !last->data;

    printf("S: %d, C: %d\n", last->data, carry);

    while (last->prev != NULL) {
        a = last->data;
        b = carry;

        carry = a * b; 
        last->data = a ^ b;

        printf("S: %d, C: %d\n", last->data, carry);

        last = last->prev;
    }

    traverse(last);

    (*head_ref) = last;    
}

void DEC(struct Node** head_ref) {

}

int main() {
    char bits[1000];
    scanf("%s%*c", bits);

    int len = strlen(bits);
    printf("String Length: %d\n", len);

    struct Node* head = NULL;

    for (int i = 0; i < len; ++i) {
        append(&head, (int)bits[i] - (int)'0');
    }

    // LS(&head, 0);

    // RS(&head, 0);
    INC(&head);

    traverse(head);
    return 0;
}