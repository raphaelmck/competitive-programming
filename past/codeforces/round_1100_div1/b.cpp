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
        vector<ll> a(n), b(n);

        for (int i=0; i<n; ++i) cin >> a[i];
        for (int i=0; i<n; ++i) cin >> b[i];
        
        ll sum = 0;
        ll best = -1;
        for (int i=0; i<n; ++i) {
            sum += max(a[i], b[i]);
            best = max(best, min(a[i], b[i]));
        }

        cout << sum + best << '\n';
	}
    
	return 0;
}
