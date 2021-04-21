#include <stdio.h>
#include <stdlib.h>

#define ll long long int
#define N (int)1e5
#define HASH_SIZE 20

typedef struct HashNode_t {
    struct HashNode_t *next;
    ll key, data;
} HashNode;

HashNode *createHashNode(ll key, ll data) {
    HashNode *hn = (HashNode *)malloc(sizeof(HashNode));

    hn->next = NULL;
    hn->key = key;
    hn->data = data;
}

typedef struct {
    HashNode *slots[HASH_SIZE];
} HashTable;

HashTable *createHashTable() {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));

    for (int i = 0; i < HASH_SIZE; ++i) {
        ht->slots[i] = NULL;
    }
}

ll hash(ll key) { return key % HASH_SIZE; }

void insert(HashTable *ht, ll key, ll data) {
    HashNode *hn = createHashNode(key, data);

    ll slot = hash(key);
    HashNode *slotNode = ht->slots[slot];

    if (!slotNode) {
        ht->slots[slot] = hn;
        return;
    }

    if (slotNode->key == key) {
        slotNode->data = data;
        return;
    }

    while (slotNode->next) {
        if (slotNode->key == key) {
            slotNode->data = data;
            return;
        }

        slotNode = slotNode->next;
    }

    slotNode->next = hn;
}

ll get(HashTable *ht, ll key) {
    ll slot = hash(key);

    HashNode *node = ht->slots[slot];

    while (node && node->key != key) {
        node = node->next;
    }

    if (!node) return -1;

    return node->data;
}

int main() {
    HashTable *hashtable = createHashTable();

    insert(hashtable, 2, 5);
    insert(hashtable, 2, 8);
    insert(hashtable, 1, 7);

    printf("[%lld]: %lld\n", (ll)1, get(hashtable, (ll)1));
    printf("[%lld]: %lld\n", (ll)2, get(hashtable, (ll)2));
    printf("[%lld]: %lld\n", (ll)3, get(hashtable, (ll)3));

    return 0;
}