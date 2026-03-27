#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {

		ll n, m;
		cin >> n >> m;

		if(m < n || m > n*(n+1)/2) {
			cout << -1 << endl;
			continue;
		}

		if(m==1) {
			cout << 1 << endl;
			continue;
		}

		auto S = [&](ll x) {
			return x * n - x*(x-1)/2;	
		};

		ll lo=1, hi=n;
		while(lo<hi) {
			ll mid = (lo + hi) >> 1;
			if(S(mid) >= m) hi = mid;
			else lo = mid+1;
		}
		ll x = lo;
		ll minM = n - 1 + x;
		ll change = m - minM;

		vector<int> parent(n+1, -1);

		if(x==1) {
			for(int v=2; v<=n; ++v) parent[v] = 1;
		} else {
			parent[1] = x;
			for(int v=2; v<=n; ++v) {
				if(v==x) continue;
				parent[v] = 1;
			}
		}
		
		ll bigChange = x-1;
		for(ll v=n; v>x && change >= bigChange; v--) {
			parent[v] = x;
			change -= bigChange;
		}

		if(change > 0) {
			ll v = change + 1;
			parent[v] = x;
			change = 0;
		}

		cout << x << endl;
		for(int v=1; v<=int(n); v++) {
			if(v==x) continue;
			cout << parent[v] << ' ' << v << endl;
		}
	}
    
	return 0;
}

