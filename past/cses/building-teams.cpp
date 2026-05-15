#include <bits/stdc++.h> 
using namespace std;

bool dfs(int x, vector<int>& color, vector<vector<int>>& adj) {
    stack<int> st;
    st.push(x); 
    color[x] = 1;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = 3 - color[u];
                st.push(v);
            } else if (color[u] == color[v]) {
                return false;
            }
        }
    }

    return true;
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

    vector<int> color(n+1);
    for (int i=1; i<n+1; ++i) {
        if (color[i] == 0) {
            if (!dfs(i, color, adj)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i=1; i<n+1; ++i) {
        cout << color[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}

    
    