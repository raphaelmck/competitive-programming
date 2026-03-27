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
	
		int n, j, k;
		cin >> n >> j >> k;
		vector<int> a(n);
		int max_strength=INT_MIN;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			max_strength = max(max_strength, a[i]);
		}

		int j_strength = a[j-1];

		bool ans;
		if(k >= 2)
			ans = true;
		else
			ans = (j_strength == max_strength);
		
		cout << (ans ? "YES\n" : "NO\n");
	}
    
	return 0;
}

