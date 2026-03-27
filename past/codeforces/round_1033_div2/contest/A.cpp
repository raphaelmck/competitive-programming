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

		ll l[3], b[3];
		for(int i=0; i<3; ++i) cin >> l[i] >> b[i];

		ll A = l[0]*b[0] + l[1]*b[1] + l[2]*b[2];
		ll s = llround(sqrt((long double)A));
		if(s*s !=A) {
			cout << "NO\n";
			continue;
		}
		
		bool ok = false;
		// all side by side
		if(b[0]==s && b[1]==s && b[2]==s && l[0]+l[1]+l[2]==s) ok = true;

		// all stacked
		if(l[0]==s && l[1]==s && l[2]==s && b[0]+b[1]+b[2]==s) ok = true;

		// pick on to span height or width
		for(int i=0; i<3; ++i) {
			int j=(i+1) % 3, k=(i+2) % 3;
			
			// full height on left, stack j, k vertically on right
			if(b[i]==s) {
				ll w = l[i];
				if(w<s) {
					if(l[j]==s-w && l[k]==s-w && b[j]+b[k]==s) ok = true;
				}
			}

			// full width on top, j, k side by side beneath
			if(l[i]==s) {
				ll h = b[i];
				if(h<s) {
					if(b[j]==s-h && b[k]==s-h && l[j]+l[k]==s) ok = true;
				}
			}
		}

		cout << (ok ? "YES\n" : "NO\n");
	}
    
	return 0;
}

