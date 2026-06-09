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

		if (n==2) {cout << "2 1 1 2 1 2 2 1" << '\n'; continue; }

		for (int i=1; i<=n; ++i) cout << i << ' ';
		for (int i=1; i<=n; ++i) cout << i << ' ';

		cout << n << ' ';
		for (int i=1; i<n; ++i) cout << i << ' ';

		for (int i=1; i<=n; ++i) cout << i << ' ';
		cout << '\n';
	}
    
	return 0;
}

