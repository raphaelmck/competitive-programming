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
		ll s;
		cin >> n >> s;
		int pots=0;
		for(int i=0; i<n; ++i) {
			ll dx, dy, x, y;
			cin >> dx >> dy >> x >> y;
			if((dx==dy && x==y) || dx==-dy && x+y==s) pots++;
		}
		cout << pots << endl;
	}
    
	return 0;
}

