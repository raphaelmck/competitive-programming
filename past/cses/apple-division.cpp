#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> a(n);

    ll total = 0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        total += a[i];
    }

    ll ans = LLONG_MAX;
    for (int mask=0; mask<(1<<n); ++mask) {
        ll sum = 0;
        
        for (int i=0; i<n; ++i) {
            if (mask & (1 << i)) sum += a[i];
        }

        ans = min(ans, abs(total - 2*sum));
    }

    cout << ans << '\n';

    return 0;
}