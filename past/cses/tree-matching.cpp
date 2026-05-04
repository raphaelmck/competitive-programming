#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n == 1) { cout << 0 << '\n'; return 0; }
    if (n == 2) { cout << 1 << '\n'; return 0; }

    vector<vector<int>> adj(n+1);

    for (int i=0; i<n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n+1, 0);
    vector<int> order;

    stack<int> st;
    st.push(1);
    parent[1] = -1;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            st.push(v);
        }
    }

    vector<bool> matched(n+1, false);
    int ans = 0;
    reverse(order.begin(), order.end());

    for (int u : order) {
        if (matched[u]) continue;

        for (int v : adj[u]) {
            if (parent[v] == u && !matched[v]) {
                matched[u] = matched[v] = true;
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
