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
        ll curr;
        cin >> n >> curr;

        vector<array<ll,3>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2]; 

        sort(a.begin(), a.end());

        priority_queue<pair<ll,int>> pq;
        int idx = 0;

        while(true) {
            while(idx < n && a[idx][0] <= curr) {
                pq.emplace(a[idx][2], idx);
                ++idx;
            }

            bool played = false;
            while(!pq.empty()) {
                auto [pay, i] = pq.top();
                if(pay <= curr || curr > a[i][1]) {
                    pq.pop();
                    continue;
                }

                curr = pay;
                played = true;
                pq.pop();
                break;
            }
            if(!played) break;
        }

        cout << curr << "\n";
	}
    
	return 0;
}

