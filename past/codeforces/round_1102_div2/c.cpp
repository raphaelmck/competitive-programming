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

        vector<ll> h(n);
        for (int i=0; i<n; ++i) cin >> h[i];

        vector<ll> ans(n);

        for (int empty=0; empty<n; empty++) {
            vector<ll> pref(n), suff(n);

            ll mx=0;
            for (int k=0; k<n; ++k) {
                mx = max(mx, h[(empty + k) % n]);
                pref[k] = mx;
            }

            mx = 0;
            for (int k=n-1; k>=0; --k) {
                mx = max(mx, h[(empty + k) % n]);
                suff[k] = mx;
            }

            ll total = 0;

            for (int k=1; k<n; ++k) {
                ll leftMax = pref[k - 1];
                ll rightMax = suff[k];

                total += min(leftMax, rightMax);
            }

            ans[empty] = total;
        }

        for (int i=0; i<n; ++i) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}
