#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<string> map(n);
    for (int i=0; i<n; ++i) cin >> map[i];

    pair<int, int> A, B;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (map[i][j] == 'A') A = {i, j};
            if (map[i][j] == 'B') B = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> parent(n, vector<char>(m, 0));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char dir[4] = {'D', 'U', 'R', 'L'};

    queue<pair<int, int>> q;
    q.push(A);
    visited[A.first][A.second] = true;
    bool found = false;

    while (!q.empty() && !found) {
        auto [x, y] = q.front(); q.pop();

        for (int d=0; d<4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || map[nx][ny] == '#') continue;

            visited[nx][ny] = true;
            parent[nx][ny] = dir[d];
            q.push({nx, ny});

            if (make_pair(nx, ny) == B) { found = true; break; }
        }
    }

    if (!visited[B.first][B.second]) { cout << "NO\n"; return 0; }

    string path;
    int x = B.first, y = B.second;
    while (make_pair(x, y) != A) {
        char c = parent[x][y];
        path.push_back(c);
        if (c == 'D') x--;
        else if (c == 'U') x++;
        else if (c == 'R') y--;
        else if (c == 'L') y++;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << '\n' << path << '\n';
}
