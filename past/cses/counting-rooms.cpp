#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(vector<vector<char>>& map, int i, int j, int n, int m) {
    map[i][j] = 'v';
    for (int d=0; d<4; ++d) {
        int ni = i + dy[d];
        int nj = j + dx[d];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] == '.') {
            bfs(map, ni, nj, n, m);
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<char>> map(n);

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            char c; cin >> c;
            map[i].push_back(c);
        }
    }

    int ans = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (map[i][j] == '.') {
                ans++;
                bfs(map, i, j, n, m);
            }
        }
    }

    cout << ans << '\n';
}
