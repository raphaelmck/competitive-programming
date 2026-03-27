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

		string l, r;
		cin >> l >> r;
		if(l == r) {
			cout << 2 * l.size() << endl;
			continue;
		}
		
		int ptr=0;
		while((ptr < l.size()) && l[ptr] == r[ptr]) ptr++; // longest common prefix
		if(l[ptr] + 1 < r[ptr]) cout << 2 * ptr << endl; // choose digit in between, the rest can be in range different
		else {
			int res = 2 * ptr + 1; // lcp and current digit (matches one)
			for(int i = ptr+1; i<l.size(); ++i) {
				if(l[i] == '9' && r[i] == '0') ++res;
				else break;
			}
			cout << res << endl;
		}
	}
    
	return 0;
}

