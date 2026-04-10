#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    ll mx = 0, ans = 0;
    for (ll x : a) {
        if (x < mx) ans += mx - x;
        else mx = x;
    }
    cout << ans << '\n';
}
