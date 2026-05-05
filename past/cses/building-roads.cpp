#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<bool>& visited, vector<vector<int>>& adj) {
    stack<int> st;
    st.push(v);
    visited[v] = true;
    
    while(!st.empty()) {
        int u = st.top(); st.pop();
        for (int w : adj[u]) {
            if (!visited[w]) {
                visited[w] = true;
                st.push(w);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for (int i=0; i<m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<int> reps;

    for (int i=1; i<n+1; ++i) {
        if (!visited[i]) {
            reps.push_back(i);
            dfs(i, visited, adj);
        }
    }

    int k = reps.size();
    cout << k - 1<< '\n';
    for (int i=1; i<k; ++i) {
        cout << reps[0] << ' ' << reps[i] << '\n';
    }

    return 0;
}
