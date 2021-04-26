#include <bits/stdc++.h>

#define ll int64_t
using namespace std;

const int CHAR_SIZE = 128;

string PLAYERS[] = {"Alice", "Bob"};

struct Trie {
    bool isLeaf;
    Trie *character[CHAR_SIZE];

    Trie() {
        this->isLeaf = false;
        for (int i = 0; i < CHAR_SIZE; i++) {
            this->character[i] = nullptr;
        }
    }

    void insert(string);
    bool search(string);
};

void Trie::insert(string key) {
    Trie *curr = this;

    for (int i = 0; i < key.length(); ++i) {
        if (curr->character[key[i]] == nullptr) {
            curr->character[key[i]] = new Trie();
        }

        curr = curr->character[key[i]];
    }

    curr->isLeaf = true;
}

bool Trie::search(string key) {
    if (this == nullptr) {
        return false;
    }

    Trie *curr = this;

    for (const char &c : key) {
        curr = curr->character[c];

        if (!curr) return false;
    }

    return curr->isLeaf;
}

void solution() {
    int n;
    cin >> n;

    int currentPlayer = 0;
    string word, prevWord;
    Trie *head = new Trie();

    for (int i = 0; i < n; ++i) {
        cin >> word;

        if (prevWord.length() > 0 && word.front() != prevWord.back()) {
            cout << PLAYERS[!currentPlayer];
            return;
        }

        if (head->search(word)) {
            cout << PLAYERS[!currentPlayer];
            return;
        }

        head->insert(word);

        currentPlayer = !currentPlayer;
        prevWord = word;
    }

    cout << PLAYERS[!currentPlayer];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solution();
        cout << " \n"[i == t - 1];
    }

    return 0;
}