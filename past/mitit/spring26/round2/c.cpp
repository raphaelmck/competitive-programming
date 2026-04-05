#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

const int MX = 1000005;
const int LOG = 20;
int table[MX][LOG];

struct res {
	vector<ll> L;
	vector<ll> dp;
};

res solve(int n, vector<ll>& h) {
	vector<int> p(n+1, 0);
	vector<int> st;
	st.push_back(0);

	for (int i=1; i<=n; ++i) {
		while (st.back() != 0 && h[st.back()] >=h[i]) st.pop_back();
		p[i] = st.back();
		st.push_back(i);
	}

	for (int i=1; i<=n; ++i) {
		table[i][0] = p[i];
		for (int k=1; k<LOG; ++k) table[i][k] = table[table[i][k-1]][k-1];
	}

	vector<ll> L(n+1, 0);
	vector<ll> dp(n+1, 0);

	for (int i=1; i<=n; ++i) {
		L[i] = L[p[i]] + h[i] * (i - p[i]);
		dp[i] = dp[p[i]] + h[i] * (i - p[i]);

		if (p[i] != 0) {
			int cur = p[i] - 1;
			for (int k = LOG - 1; k >= 0; --k) {
				if (table[cur][k] != 0 && h[table[cur][k]] >= h[i]) {
					cur = table[cur][k];
				}
			}
			if (cur != 0 && h[cur] >= h[i]) {
				cur = table[cur][0];
			}

			int p2 = cur;
			ll val = L[p2] + h[i] * (i - p2);
			dp[i] = max(dp[i], val);
		}
	}

	return {L, dp};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {
		int n;	
		cin >> n;
		vector<ll> h(n+1, 0);
		for (int i=1; i<=n; ++i) cin >> h[i];

		res left = solve(n, h);

		vector<ll> rev(n+1, 0);
		for (int i=1; i<=n; ++i) rev[i] = h[n-i+1];
		res right = solve(n, rev);

		ll mx = 0;

		for (int k=1; k<=n; ++k) {
			ll l1 = left.L[k];
			ll l2 = left.dp[k];

			int revk = n-k+1;
			ll r1 = right.L[revk];
			ll r2 = right.dp[revk];

			ll val1 = l2 + r1 - h[k];
			ll val2 = l1 + r2 - h[k];

			mx = max({mx, val1, val2});
		}

		cout << mx << '\n';
		
	}
    
	return 0;
}

