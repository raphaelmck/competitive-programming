#include <bits/stdc++.h>
using namespace std;

void hanoi (int k, int from, int spare, int to) {
    if (k == 0) return;

    hanoi(k-1, from, to, spare);
    cout << from << ' ' << to << '\n';
    hanoi(k-1, spare, from, to);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 2, 3);

    return 0;
}