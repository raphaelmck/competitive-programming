#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

void solve() {
    int n;	
    cin >> n;

    vector<int> a(n);
    int k =0;

    for (int i=0; i<n; ++i) {
        cin >> a[i];
        if (i>0) k = max(k, a[i-1] - a[i]);
    }

    int c = 0;
    for (int i=0; i<n-1; ++i) {
        ll cur = a[i] + c * 1LL*k;
        if (cur>a[i+1]+k) {
            cout << "NO\n";
            return;
        }
        c = (cur > a[i+1] ? 1 : 0);
    }
    cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {
        solve();
	}
    
	return 0;
}

