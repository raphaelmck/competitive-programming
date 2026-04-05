#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

#define MAXN 200005
ll fact[MAXN], inv[MAXN], pow2[MAXN];

ll power(ll b, ll e) {
	ll r = 1;
	b %= MOD;
	while (e > 0) {
		if (e % 2 == 1) r = (r * b) % MOD;
		b = (b * b) % MOD;
		e /= 2;
	}
	return r;
}

ll modInv(ll n) {
	return power(n, MOD - 2);
}

void comp() {
	fact[0] = 1;
	inv[0] = 1;
	pow2[0] = 1;
	for (int i =1; i<MAXN; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
		pow2[i] = (pow2[i-1] * 2) % MOD;
	}
	inv[MAXN-1] = modInv(fact[MAXN -1]);
	for (int i=MAXN-2; i>=1; --i) {
		inv[i] = (inv[i+1] * (i+1)) % MOD;
	}
}

ll nCr(int n, int r) {
	return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
}

int sz[MAXN];
ll dp[MAXN];
vector<int>adj[MAXN];

void dfs(int u, int p) {
	sz[u] = 1;
	int e = 0, o = 0;
	ll ways = 1;

	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];

		if (sz[v] % 2 == 1) o++;
		else e++;

		ways = (ways * dp[v]) % MOD;
	}

	sz[u] %= 2;

	ll oways = nCr(o, o/2);
	ll eways = (o > 0) ? pow2[e] : 1;

	ll rways = (oways * eways) % MOD;
	dp[u] = (ways * rways) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
	comp();
    while (t--) {
		int n;	
		cin >> n;

		for (int i=1; i<=n; ++i) adj[i].clear();
		for (int i=0; i<n-1; ++i) {
			int u,v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);

		}

		dfs(1, 0);
		cout << dp[1] << '\n';
		
	}
    
	return 0;
}

