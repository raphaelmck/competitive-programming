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
        vector<int> a(n), cnt(n+1, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }

        int m = 0;
        while(m <= n && cnt[m] > 0) 
            m++;

        vector<int> diff(n+2, 0);
        for(int x = 0; x <= m; x++){
            int L = cnt[x];
            int U = n - x;
            if(L <= U){
                diff[L] += 1;
                diff[U+1] -= 1;
            }
        }

        vector<int> ans(n+1);
        int cur = 0;
        for(int k = 0; k <= n; k++){
            cur += diff[k];
            ans[k] = cur;
        }
		
        for(int k = 0; k <= n; k++){
            cout << ans[k] << (k==n?'\n':' ');
        }
		
	}
    
	return 0;
}

