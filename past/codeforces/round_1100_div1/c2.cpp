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
        vector<ll> a(n+1), abspref(n+1), suf(n+2);
        for (int i=1; i<=n; ++i){ 
            cin >> a[i];
            abspref[i] = abspref[i-1] + llabs(a[i]);
        }
        for (int i=n; i>=1; --i) {
            suf[i] = suf[i+1] + a[i];
        }

        ll best = suf[1];
        int besti = -1;
        for (int i=1; i<=n; ++i) {
           if (a[i] >0) {
                ll c = abspref[i-1] - a[i] + suf[i+1];
                if (c > best) {
                    best = c;
                    besti = i;
                }
            }
        }

        vector<int> ans;
        if (besti != -1) {
            bool f = false;
            for (int i=besti-1; i>=1; --i) {
                bool pos = a[i] > 0;
                if (f) pos = !pos;
                if (pos) {
                    ans.push_back(i);
                    f = !f;
                }
            }
            ans.push_back(besti);
        }

        cout << ans.size() << '\n';
        for (int i=0; i<ans.size(); ++i) {
            cout << ans[i] << (i == ans.size()-1 ? "" : " ");
        }
        cout << '\n';
        
	}
    
	return 0;
}
