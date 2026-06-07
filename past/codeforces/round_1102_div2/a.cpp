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

		vector<ll> a(n);
		for (int i=0; i<n; ++i) cin >> a[i];

		sort(a.rbegin(), a.rend());

		if (n==2) { cout << a[0] << ' ' << a[1] << '\n'; continue; }

		bool ok = true;
		for (int i=0; i<n-2; ++i) {
			if (a[i] % a[i+1] != a[i+2]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << a[0] << ' ' << a[1] << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	return 0;
}
