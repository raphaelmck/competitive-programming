#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<string> grid(n);
    for (int i=0; i<n; ++i) cin >> grid[i];

    vector<string> ans(n, string(m, 'A'));
    string chars = "ABCD";

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            for (char c : chars) {
                if (c == grid[i][j]) continue;
                if (i > 0 && c == ans[i-1][j]) continue;
                if (j > 0 && c == ans[i][j-1]) continue;

                ans[i][j] = c;
                break;
            }
        }
    }

    for (int i=0; i<n; ++i) cout << ans[i] << '\n';

    return 0;
}
