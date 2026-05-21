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
        vector<pair<int, int>> reached;
        reached.reserve(n*100);

        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            int cur = a, d=0;

            vector<int> seen;
            while(true) {
                bool found = false;
                for (int x : seen) {
                    if (x ==cur) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
                seen.push_back(cur);
                reached.push_back({cur, d});
                
                if (cur & 1) {
                    cur +=1;
                } else {
                    cur /= 2;
                }
                d++;
            }
        }

        sort(reached.begin(), reached.end()); 
        int ans = 2e9;

        for (int i=0; i<reached.size();) {
            int target = reached[i].first;
            int cnt = 0, sum = 0;
            while (i<reached.size() && reached[i].first == target) {
                cnt++;
                sum += reached[i].second;
                ++i;
            }
            if (cnt == n) ans = min(ans, sum);
        }

        cout << ans << '\n';
		
	}
    
	return 0;
}

