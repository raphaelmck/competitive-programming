#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(int u, vector<vector<int>>& adj) {
    vector<int> dist(adj.size(), -1);
    stack<int> st;
    st.push(u);
    dist[u] = 0;
    
    int farthest = u;
    int maxDist = 0;
    while (!st.empty()) {
        int v = st.top(); st.pop();

        if (dist[v] > maxDist) {
            maxDist = dist[v];
            farthest = v;
        }

        for (int c : adj[v]) {
            if (dist[c] == -1) {
                dist[c] = dist[v] + 1;
                st.push(c);
            }
        }
    }

    return {farthest, maxDist};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto point1 = dfs(1, adj);
    auto point2 = dfs(point1.first, adj);

    cout << point2.second << '\n';
}
