#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = 1;
        while (n < size) n *= 2;
        tree.assign(2*n, INF);
    }

    void build(vector<int> a) {
        for (int i=0; i<(int)a.size(); ++i) {
            tree[n+i] = a[i];
        }
        for (int i=n-1; i>=1; --i) {
            tree[i] = min(tree[2*i], tree[2*i+1]);
        }
    }

    void update(int pos, int val) {
        pos += n;
        tree[pos] = val;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = min (tree[2*pos], tree[2*pos+1]);
        }
    }

    int query(int l, int r) {
        l += n;
        r += n;

        int ans = INF;
        while (l <= r) {
            if (l % 2 == 1) ans = min(ans, tree[l++]);
            if (r % 2 == 0) ans = min(ans, tree[r--]);

            l /= 2;
            r /= 2;
        }

        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    SegmentTree seg(n);
    seg.build(a);

    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            int k, u;
            cin >> k >> u;

            k--;
            seg.update(k, u);
        } else {
            int a, b;
            cin >> a >> b;

            a--; b--;
            cout << seg.query(a, b) << '\n';
        }
    }
    
    return 0;
}
