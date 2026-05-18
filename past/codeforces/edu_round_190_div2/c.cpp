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

        ll sum = 0;
        ll blocks = 0;
        ll slots = 0;
        ll singletons = 0;

        for (int i=0; i<n; ++i) {
            ll c; cin >> c;

            if (c >= 2) {
                sum += c;
                blocks++;
                slots += (c/2)-1;
            } else {
                singletons++;
            }
        }

        if (blocks == 0) { cout << 0 << '\n'; continue; }
        if (blocks == 1) slots++;

        ll ans = sum + min(slots, singletons);
        if (ans < 3) { cout << 0 << '\n'; continue; }
        
        cout << ans << '\n';
	}
    
	return 0;
}

