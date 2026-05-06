#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<long long> pref(n+1, 0);

    for (int i=1; i<n+1; ++i) {
        long long x;
        cin >> x;
        pref[i] = pref[i-1] + x;
    }

    for (int i=0; i<q; ++i) {
        int a, b; cin >> a >> b;
        cout << pref[b] - pref[a-1] << '\n';
    }
    
    return 0;
}
