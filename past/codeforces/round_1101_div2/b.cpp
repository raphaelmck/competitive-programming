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

		ll cs = 0;
		ll mh = 2e18;

		for (int i=1; i<=n; ++i) {
			ll a; cin >> a;

			cs += a;
			mh = min(mh, cs/i);

			cout << mh << (i ==n ? "" : " ");
		}
		cout << '\n';
		
	}
    
	return 0;
}

