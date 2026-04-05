#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int mod(ll x, int n) {
	int r = x % n;
	return r < 0 ? r + n : r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {
		int n;	
		cin >> n;
		int k, x, y; cin >> k >> x >> y;

		vector<int> a(k);
		vector<ll> p(k+1, 0);
		for (int i=0; i<k; ++i) {
			cin >> a[i];
			p[i+1] = mod(p[i] + a[i], n);
		}

		vector<int> nxt(n, -1);
		vector<int> dp(k+1, 0);

		dp[k] = y;
		nxt[p[k]] = k;
		
		for (int i = k-1; i>=1; --i) {
			int j = nxt[mod(x - y + p[i], n)];
			if (j!=-1) dp[i] = dp[j];
			else dp[i] = mod(y + p[k] - p[i], n);

			nxt[p[i]] = i;
		}

		bool first = true;
		for (int i=0; i<n; ++i) {
			if (i == x) continue;

			int j = nxt[mod(x - i, n)];
			int ans;
			if (j!=-1) ans = dp[j];
			else ans = mod(i + p[k], n);

			if (!first) cout << ' ';
			cout << ans;
			first = false;
		}
		cout << '\n';
	}
    
	return 0;
}

