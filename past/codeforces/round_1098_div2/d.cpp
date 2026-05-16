#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;    
        cin >> n;

        vector<int> miny(n+2, INF);
        vector<int> maxy(n+2, 0);

        vector<int> y(n+2, 0); 
        for (int i=0; i<n; ++i) {
            int xi, yi;
            cin >> xi >> yi;
            miny[xi] = min(miny[xi], yi);
            maxy[xi] = max(maxy[xi], yi);
            y[yi] = 1;         
        }

        vector<int> sumy(n+2, 0);
        for (int i=1; i<=n; ++i) {
            sumy[i] = sumy[i-1] + y[i];
        }

        vector<int> prefmin(n+2, INF);
        vector<int> prefmax(n+2, 0);
        for (int i=1; i<=n; ++i) {
            prefmin[i] = min(prefmin[i-1], miny[i]);
            prefmax[i] = max(prefmax[i-1], maxy[i]);
        }

        vector<int> sufmin(n+2, INF);
        vector<int> sufmax(n+2, 0);
        for (int i=n; i>=1; --i) {
            sufmin[i] = min(sufmin[i+1], miny[i]);
            sufmax[i] = max(sufmax[i+1], maxy[i]);
        }

        ll ans = 0;
        for (int x=1; x<n; ++x) {
            if (maxy[x] == 0) continue; 
            
            if (prefmax[x] == 0 || sufmax[x+1] == 0) continue;
            
            int lmin = prefmin[x];
            int lmax = prefmax[x];
            int rmin = sufmin[x+1];
            int rmax = sufmax[x+1];
            int l = max(lmin, rmin);
            int h = min(lmax, rmax) - 1;

            if (l <= h) {
                ans += sumy[h] - sumy[l-1];
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
