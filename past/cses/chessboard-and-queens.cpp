#include <bits/stdc++.h>
using namespace std;

vector<string> board(8);
bool col[8], diag1[15], diag2[15];
int ans = 0;

void solve(int r) {
    if (r == 8) {
        ans++;
        return;
    }

    for (int c=0; c<8; ++c) {
        if (board[r][c] == '*') continue;

        int d1 = r - c + 7;
        int d2 = r + c;

        if (col[c] || diag1[d1] || diag2[d2]) continue;

        col[c] = diag1[d1] = diag2[d2] = true;
        solve(r+1);
        col[c] = diag1[d1] = diag2[d2] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=0; i<8; ++i) cin >> board[i];

    solve(0);

    cout << ans << '\n';

    return 0;
}
