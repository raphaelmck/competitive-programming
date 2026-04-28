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

        int n, k;
        cin >> n >> k;
        vector<ll> h(n);
        for(int i=0; i<n; ++i) cin >> h[i];

        ll h0 = h[k-1];
        ll maxH = *max_element(h.begin(), h.end());

        if(h0 == maxH) {
            cout << "YES\n";
            continue;
        }
			  
        vector<ll> ux = h;
        sort(ux.begin(), ux.end());

        ux.erase(unique(ux.begin(), ux.end()), ux.end());
        auto it0 = lower_bound(ux.begin(), ux.end(), h0);

        if(it0 != ux.end() && *it0 == h0) ux.erase(it0);

        ll curr = h0;
        bool ok = false;
        while(true) {
            ll bound = curr + h0;
            if(bound >= maxH) {
                ok = true;
                break;
            }

            auto it = upper_bound(ux.begin(), ux.end(), bound);
            if(it == ux.begin()) break;  
            --it;
            if(*it <= curr) break;        
            curr = *it;                    
        }

        cout << (ok ? "YES\n" : "NO\n");
	}
    
	return 0;
}

