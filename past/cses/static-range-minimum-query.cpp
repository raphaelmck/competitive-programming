#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> x(n); 
    for (int i=0; i<n; ++i) cin >> x[i];

    vector<int> lg(n+1);
    for (int i=2; i<=n; ++i) {
        lg[i] = lg[i/2] + 1;
    }

    int K = lg[n]+1;
    vector<vector<int>> st(K, vector<int>(n));
    st[0] = x;

    for (int k=1; k<K; ++k) {
        for (int i=0; i + (1<<k) <= n; ++i) {
            st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int len = b - a + 1;
        int k = lg[len];

        int ans = min(st[k][a], st[k][b - (1<<k) + 1]);
        cout << ans << '\n';
    }
    
    return 0;
}
