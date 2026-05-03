#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;
    long long ans = 1;
    long long base = 2;

    while (n > 0) {
        if (n & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        n >>= 1;
    }

    cout << ans << '\n';

    return 0;
}
