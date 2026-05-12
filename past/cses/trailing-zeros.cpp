#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    long long ans = 0;
    for (long long p=5; p<=n; p*=n) {
        ans += n / p;
    }

    cout << ans << '\n';

    return 0;
}
