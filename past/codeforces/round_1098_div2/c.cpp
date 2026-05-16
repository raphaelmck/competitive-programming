#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {
        unsigned ll a;
		int n;	
		cin >> a >> n;

        vector<int> d(n);
        for (int i=0; i<n; ++i) cin >> d[i];
        sort(d.begin(), d.end());

        string S = to_string(a);
        unsigned ll ans = ULLONG_MAX;
        char dmin = d[0] + '0', dmax = d[n-1] + '0';

        auto update = [&](const string& s) {
            if (s.length() > 1 && s[0] == '0') return;
            unsigned ll b = stoull(s);
            unsigned ll diff = (a > b) ? (a - b) : (b - a);

            ans = min(ans, diff);
        };
		
        if (d[0] == 0) update("0");
        if (S.length() > 1) update(string(S.length() - 1, dmax));

        char mnz = -1;
        for (int x : d) {
            if (x > 0) { mnz = x + '0'; break; }
        }
        if (mnz != -1) {
            string s2 = "";
            s2 += mnz;
            s2 += string(S.length(), dmin);
            update(s2);
        }

        for (int i=0; i<=S.length(); ++i) {
            if (i == S.length()) { update(S); break; }

            int c = S[i] - '0';
            int down = -1;
            for (int x : d) {
                if (x < c) down = max(down, x);
            }
            if (down != -1) {
                string cand = S.substr(0, i) + to_string(down) + string(S.length()-1-i, dmax);
                update(cand);
            }

            int up = 10;
            for (int x : d) {
                if (x > c) up = min(up, x);
            }
            if (up != 10) {
                string cand = S.substr(0, i) + to_string(up) + string(S.length()-1-i, dmin);
                update(cand);
            }

            bool match = false;
            for (int x : d) {
                if (x == c) match = true;
            }
            if (!match) break;
        }
        
        cout << ans << '\n';
	}
    
	return 0;
}

