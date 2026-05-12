#include <bits/stdc++.h>
using namespace std;

int dfs(int u, vector<vector<int>>& adj, vector<int>& subordinatesCnt) {
    for (int v : adj[u]) {
        subordinatesCnt[u] += dfs(v, adj, subordinatesCnt);
    }
    return subordinatesCnt[u] + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> adj(n+1);

    for (int i=2; i<=n; ++i) {
        int a; cin >> a;
        adj[a].push_back(i);
    }

    vector<int> subordinatesCnt(n+1, 0);
    dfs(1, adj, subordinatesCnt);

    for (int i=1; i<=n; ++i) {
        cout << subordinatesCnt[i] << '\n';
    }

    return 0;
}
