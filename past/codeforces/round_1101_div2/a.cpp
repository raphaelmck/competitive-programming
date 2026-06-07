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
		
		vector<int> a(n);
		for (int i=0; i<n; ++i) cin >> a[i];

		sort(a.begin(), a.end());

		int ans = n;
		for (int x : a) {
			int l = lower_bound(a.begin(), a.end(), x) - a.begin();
			int r = a.end() - upper_bound(a.begin(), a.end(), x);

			ans = min(ans, max(l, r));
		}

		cout << ans << '\n';
	}
    
	return 0;
}

