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
        vector<int> ops;
        bool flipped = false;
        for (int i=n-1; i>=0; --i) {
            int v = flipped ? -a[i] : a[i];
            if (v > 0) {
                ops.push_back(i+1);
                flipped = !flipped;
            }
        }
        
        cout << ops.size() << '\n';
        for (int i=0; i<ops.size(); ++i) {
            cout << ops[i] << (i == ops.size() - 1 ? "" : " ");
        }
        cout << '\n';
        
	}
    
	return 0;
}
