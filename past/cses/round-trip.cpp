#include <bits/stdc++.h>
using namespace std;

int u, v;

int dfs(int x, int p, vector<int>& visited, vector<int>& parent, vector<vector<int>>& adj) {
    visited[x] = 1;
    parent[x] = p;

    for (int y : adj[x]) {
        if (y == p) continue;
        if (visited[y] == 1) {
            u = y;
            v = x;
            return true;
        }
        if (!visited[y]) {
            if (dfs(y, x, visited, parent, adj)) return true;
        }
    }
    visited[x] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n+1), parent(n+1);
    for (int i=1; i<=n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, parent, adj)) {
                vector<int> cycle;
                cycle.push_back(u);
                for (int c=v; c!=u; c=parent[c]) {
                    cycle.push_back(c);
                }
            cycle.push_back(u);
            cout << cycle.size() << '\n';
            for (int x : cycle) cout << x << ' ';
            cout << '\n';
            return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
    