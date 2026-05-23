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
        vector<int> a(n), b(n);
        for (int i=0; i<n; ++i) cin >> a[i];
        for (int i=0; i<n; ++i) cin >> b[i];

        auto check = [&](int k) {
            int strongs = 0, weaks = 0;
            bool inWeak = false, hasWeak = false;
            for (int i=0; i<n; ++i) {
                int sum = (a[i] >= k) + (b[i] >= k);
                if (sum == 2) {
                    strongs++;
                    if (inWeak) {
                        if (hasWeak) weaks++;
                        inWeak = false;
                    }
                } else {
                    if (!inWeak) {
                        inWeak = true;
                        hasWeak = false;
                    }
                    if (sum == 0) hasWeak = true;
                }
            }

            if (inWeak && hasWeak) weaks++;
            return strongs > weaks;
        };

        int l=1, r=2*n, ans =1;
        while (l<=r) {
            int m = l + (r-l)/2;
            if (check(m)) {
                ans = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        cout << ans << '\n';
	}
    
	return 0;
}
