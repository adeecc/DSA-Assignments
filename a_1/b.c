#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
     Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    /* 2. put in the data  */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

void iterate(Node** node) {
    node = &((*node)->next);
}

int main() {

    int n, isPalindrome = 1;
    scanf("%d%*c", &n);

    Node* string = NULL;
    char c;

    // Fill the Linked list with half the string
    for (int i = 0; i < n / 2; ++i) {
        scanf("%c", &c);
        push(&string, c);
    }

    if (n % 2) {
        scanf("%c", &c);
    }

    // Check if the other half of the string matches
    for (int i = (n / 2) + (n % 2); i < n; ++i) {
        scanf("%c", &c);

        if (c != string->data) {
            isPalindrome = 0;
            break;
        }

        string = string->next;
    }

    if (isPalindrome) 
        printf("PALINDROME");
    
    else
        printf("NOT A PALINDROME");
    

    return 0;
}

/**
 * n = 6
0 1 2 3 4 5
a b c c b a

fill till 2 (< n / 2)
start from 3 (= n / 2)

n = 5
0 1 2 3 4
a b c b a

fill to 1 (< n / 2) or 2 (= n / 2)
start from 3 (= n / 2 + 1)
**/