#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n+1, 0) {}

    void add(int i, ll val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    ll sum(int i) {
        ll res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }

    ll sum(int l, int r) {
        return sum(r)  - sum(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; 
    cin >> n >> q;
    
    vector<ll> a(n+1);
    Fenwick fw(n);

    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        fw.add(i, a[i]);
    }

    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            ll k, u;
            cin >> k >> u;

            ll diff = u - a[k];
            a[k] = u;
            fw.add(k, diff);
        } else {
            int a, b;
            cin >> a >> b;

            cout << fw.sum(a, b) << '\n';
        }
    }
    
    return 0;
}
