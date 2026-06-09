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
		cin >> n;
		string s;
		cin >> k >> s;

		int tc=0;
		for (char c:s) {
			if (c == ')') tc++;
		}

		int prefo=0, prefc=0;
		int best = 1e9, cut=0;;
		for (int i=0; i<=n; ++i) {
			int cur = prefo + (tc-prefc);
			if (cur<best) {
				best = cur; 
				cut=i;
			}
			if (i<n) {
				if (s[i] == '(') prefo++;
				else prefc++;
			}
		}

		string ans(n, '0');
		int remove = min(best, k);
		for (int i=0; i<cut && remove>0; ++i) {
			if (s[i] == '(') { 
				ans[i] = '1';
				remove--;
			}
		}

		for (int i=cut; i<n && remove>0; ++i) {
			if (s[i] == ')') {
				ans[i] = '1';
				remove--;
			}
		}

		cout << ans << '\n';
	}
    
	return 0;
}

