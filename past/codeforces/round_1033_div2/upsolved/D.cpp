#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;

	ll i;
	ll inv[100001];
	inv[1] = 1;
	for(i=2; i<=100000; ++i) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

    while (t--) {
		ll a, b, k;
		cin >> a >> b >> k;

		ll d, ans;
		d = k * (a - 1) + 1;

		ans=k;
		for(i=1; i<=a; ++i) ans = ans * ((d-i+1) % MOD) % MOD * inv[i] % MOD;

		ll n = d % MOD;
		ll m = (ans * b - ans + 1 + MOD) % MOD;
		cout << n << ' ' << m << endl;
	}
    
	return 0;
}
