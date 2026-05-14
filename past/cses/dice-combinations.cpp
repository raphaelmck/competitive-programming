#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 1;

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=min(i, 6); ++j) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
