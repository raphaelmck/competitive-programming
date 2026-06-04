#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<int> arr(n+1), pos(n+1);

    for (int i=1; i<=n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int i=1; i<n; ++i) {
        if (pos[i] > pos[i+1]) rounds++;
    }

    auto bad = [&](int x) {
        if (x<1 || x >= n) return false;
        return pos[x] > pos[x+1];
    };

    while (m--) {
        int a, b; cin >> a >> b;
        int x = arr[a], y = arr[b];

        set<int> affected;
        affected.insert(x-1);
        affected.insert(x);
        affected.insert(y-1);
        affected.insert(y);

        for (int v : affected) rounds -= bad(v);

        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);

        for (int v : affected) rounds += bad(v);

        cout << rounds << '\n';
    }

    return 0;
}
