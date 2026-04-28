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
        vector<int> a(n+1), ps(n+1, 0);
        for(int i=1; i<=n; ++i) {
            cin >> a[i];
            ps[i] = ps[i-1] + a[i];
        }

        int ans=0;
        int i=1;
        while(i <= n-k+1) {
            if(ps[i+k-1] - ps[i-1] == 0) {
                ++ans;
                i += k + 1;  
            } else {
                ++i;
            }
        }

        cout << ans << "\n";
		
	}
    
	return 0;
}

