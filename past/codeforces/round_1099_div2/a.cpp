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
        for (int i=1; i<=n; ++i) {
            cout << 2*i-1 << (i == n ? "" : " ");
        }
        cout << '\n';

	}
    
	return 0;
}
