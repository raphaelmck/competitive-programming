#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i=1; i<=m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_set<int> visited;
    visited.insert(n);
    vector<int> parent(n+1, -1);
    vector<int> depth(n+1, 1);

    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : adj[x]) {
            if (!visited.count(y)) {
                visited.insert(y);
                parent[y] = x;
                depth[y] = depth[x] + 1;
                q.push(y);
            }
        }
    }

    if (parent[1] == -1) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << depth[1] << '\n';
        int p = 1;
        while (p != n) {
            cout << p << ' ';
            p = parent[p];
        }
        cout << n << '\n';
    }

    return 0;
}
