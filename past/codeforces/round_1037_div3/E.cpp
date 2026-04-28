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

		int n;
		cin >> n;

		vector<ll> p(n+1), s(n+1);
        for(int i=1; i<=n; ++i) cin >> p[i];
        for(int i=1; i<=n; ++i) cin >> s[i];

        bool ok = true;

		for(int i=2; i<=n && ok; ++i) {
            if(p[i-1] % p[i] != 0) ok = false;
        }
			  
        for(int i=1; i<n && ok; ++i) {
            if(s[i+1] % s[i] != 0) ok = false;
        }

		if(n > 1) {
            if(gcd(p[1], s[2]) != s[1]) ok = false;
            if(gcd(p[n-1], s[n]) != p[n]) ok = false;
        } else {
            if(p[1] != s[1]) ok = false;
        }
		
        for(int i=2; i<=n-1 && ok; ++i) {
            ll u = p[i-1] / p[i];
            ll v = s[i+1] / s[i];
            ll x = s[i] / gcd(p[i], s[i]);
            ll y = p[i] / gcd(p[i], s[i]);
            if(gcd(u, x) != 1 || gcd(v, y) != 1) ok = false;
        }

        cout << (ok ? "YES\n" : "NO\n");
	}
    
	return 0;
}

