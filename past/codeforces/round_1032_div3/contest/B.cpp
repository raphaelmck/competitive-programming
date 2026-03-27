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
		string s;
		cin >> n >> s;

		vector<int> suffix(26, 0), prefix(26, 0);
		for(char c : s) suffix[c - 'a']++;

		bool valid = false;
		for(int i=1; i<=n-2; ++i) {
			int char_i = s[i] - 'a';
			suffix[char_i]--;
			if(prefix[char_i] > 0 || suffix[char_i] > 0) {
				valid = true;
				break;	
			}
			prefix[char_i]++;
		}
		cout << (valid ? "Yes\n" : "No\n");
    }

       	 return 0;
}

