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
        int mina = 1e8;
        int maxa = -1;
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            mina = min(mina, a);
            maxa = max(maxa, a);
        }
        cout << (maxa-mina+1) / 2 << '\n';

	}
    
	return 0;
}
