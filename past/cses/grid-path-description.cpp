#include <bits/stdc++.h>
using namespace std;

string path;
bool visited[9][9];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dirChar[4] = {'D', 'U', 'L', 'R'};

int dfs(int r, int c, int step) {
    if (r == 7 && c == 1) return step == 48;
    if (step == 48) return 0;

    if (visited[r-1][c] && visited[r+1][c] && !visited[r][c-1] && !visited[r][c+1]) return 0;
    if (!visited[r-1][c] && !visited[r+1][c] && visited[r][c-1] && visited[r][c+1]) return 0;

    visited[r][c] = true;

    int ans = 0;
    char ch = path[step];
    for (int d=0; d<4; ++d) {
        if (ch != '?' && ch != dirChar[d]) continue;

        int nr = r + dr[d];
        int nc = c + dc[d];

        if (!visited[nr][nc]) ans += dfs(nr, nc, step+1);
    }

    visited[r][c] = false;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> path;

    for (int i=0; i<9; ++i) {
        visited[0][i] = true;
        visited[i][0] = true;
        visited[8][i] = true;
        visited[i][8] = true;
    }

    cout << dfs(1, 1, 0) << '\n';

    return 0;
}