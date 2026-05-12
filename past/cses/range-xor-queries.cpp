#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; 
    cin >> n >> q;

    vector<int> pref(n+1);
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        pref[i] = x ^ pref[i-1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (pref[b] ^ pref[a-1]) << '\n';
    }

    return 0;
}
