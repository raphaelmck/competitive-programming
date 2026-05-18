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
        string s; cin >> s;
        int n = s.length();

        int c13 = 0;
        for (char c : s) {
            if (c == '1' || c == '3') {
                c13++;
            }
        }

        int kept = c13;
        int cur2 = 0, cur13 = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '2') {
                cur2++;
            } else if (s[i] == '1' || s[i] == '3') {
                cur13++;
            }

            kept = max(kept, cur2 + (c13 - cur13));
        }

        cout << n - kept << '\n';
		
	}
    
	return 0;
}

