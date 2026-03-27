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
		
        ll n, l, r, k;
        cin >> n >> l >> r >> k;

        // n odd : all ls
        if (n & 1) {
            cout << l << "\n";
            continue;
        }

        // n even
        if (n == 2) {
            cout << "-1\n";
            continue;
        }

        // next power of two above l
		ll c=1;
		while(c<=l) {
			c <<= 1;
		}

        if (c > r) {
            // can't pick two copies of c
            cout << "-1\n";
            continue;
        }

        if (k <= n - 2) 
            cout << l << "\n";
        else
            cout << c << "\n";	}
    
	return 0;
}

