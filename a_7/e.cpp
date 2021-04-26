#include <bits/stdc++.h>

using namespace std;

const int M = 11;

bitset<10> calcParityEqvt(int x) {
    bitset<10> eqvt = 0;
    int i = 0, d;
    while (x) {
        d = x % 10;
        eqvt.set(i++, (d & 1));
        x /= 10;
    }

    return eqvt;
}

int main() {
    int n;
    cin >> n;

    string instr;
    int x;

    array<int, 1 << 10> count;
    count.fill({});

    while (--n) {
        cin >> instr >> x;

        int mask = 0;

        for (int i = 0; i < M; ++i, x /= 10) {
            mask += ((x % 10) & 1) << i;
        }

        if (instr[0] == 'a')
            count[mask]++;

        else if (instr[0] == 'd')
            count[mask]--;

        if (instr[0] == 'q') cout << count[mask] << endl;
    }
    return 0;
}