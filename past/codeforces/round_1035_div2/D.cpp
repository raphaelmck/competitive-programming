#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        long long m;
        cin >> n >> m;

        // dp[j] will hold f_i[j] for the current i
        vector<long long> dp(n+1, 0);
        dp[0] = 1;  // base: with i = n+1, choosing 0 tokens has weight 1

        // iterate i = n, n-1, ..., 1
        for(int i = n; i >= 1; --i){
            // j_max = how many we could choose from [i..n]:
            int jmax = n - i + 1;
            // update dp[j] in descending order so we don't overwrite dp[j-1]
            for(int j = jmax; j >= 1; --j){
                // factor = i * (n - i + 1 - (j-1))
                long long factor = (long long)i * ( (n - i + 1) - (j - 1) ) % m;
                dp[j] = (dp[j] + dp[j-1] * factor) % m;
            }
            // dp[0] stays the same (i.e. you can always skip picking i)
        }

        // answer = sum of dp[j] for j = 0..n
        long long ans = 0;
        for(int j = 0; j <= n; ++j){
            ans = (ans + dp[j]) % m;
        }
        cout << ans << "\n";
    }

    return 0;
}
