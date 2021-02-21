#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (uint8_t)1
#define FALSE (uint8_t)0

#define ll int64_t
#define ull uint64_t


int updateStrength(int R_i, int R_j, int a) {
    int temp = R_i - a * (R_i - R_j);
    return (temp >= 0) ? temp : -temp;
}

typedef struct {
    int idx, strength;
} Player;


int main() {
    int n, a, b, s;
    scanf("%d %d %d", &n, &a, &b);

    int playing[n], numPlaying = n, prevPlaying = n;
    Player players[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &s);
        players[i] = (Player) {.idx = i + 1, .strength = s};
        playing[i] = 1;
    }


    while (numPlaying > 1) {

        if (numPlaying & 1) {
            players[numPlaying - 1].strength += b;
        }

        for (int i = 0; i < numPlaying; i += 2) {
            if (players[i].strength == players[i + 1].strength) {
                playing[i] = playing[i + 1] = 0;
                numPlaying -= 2;
            } else if (players[i].strength < players[i + 1].strength) {
                playing[i] = 0;
                players[i + 1].strength = updateStrength(players[i + 1].strength, players[i].strength, a);
                numPlaying--;
            } else {
                playing[i + 1] = 0;
                players[i].strength = updateStrength(players[i].strength, players[i + 1].strength, a);
                numPlaying--;
            }
        }

        int rear = 0;
        for (int i = 0; i < prevPlaying; i++) {
            if (playing[i]) {
                players[rear] = players[i];
                playing[rear] = 1;
                rear++;
            }
        }

        for (int i = rear; i < n; ++i) {
            playing[i] = 0;
        }

        prevPlaying = numPlaying;
    }

    if (numPlaying == 0) 
        printf("-1 -1");
    else {
        printf("%d %d", players[0].idx, players[0].strength);
    }

    return 0;
}