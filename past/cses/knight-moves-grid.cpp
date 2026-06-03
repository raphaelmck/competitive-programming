#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, -1));

    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k=0; k<8; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny,});
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}