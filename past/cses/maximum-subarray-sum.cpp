#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    long long ans = -1e18;
    long long cur = 0;

    for (int i=0; i<n; ++i) {
        long long x; cin >> x;

        cur = max(x, cur + x);
        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
