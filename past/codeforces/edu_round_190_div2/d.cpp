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
        vector<int> a(n+1), b(n+1);
        for (int i=1; i<=n; ++i) cin >> a[i];
        for (int i=1; i<=n; ++i) cin >> b[i];

        vector<int> fail(n+2, n+1);
        ll ans = 0;

        for (int i=n; i>=1; --i) {
            if (a[i] != b[i]) {
                fail[a[i]] = i;
                fail[b[i]] = i;
            } else {
                int x = a[i];
                fail[x] = fail[x+1];
            }
        
            int maxR = fail[1] - 1;
            if (maxR >= i) {
                ans += (maxR - i + 1);
            }
        }

        cout << ans << '\n';
	}
    
	return 0;
}

