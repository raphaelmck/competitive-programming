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

		int n; cin >> n;
		ll px, py, qx, qy;
		cin >> px >> py >> qx >> qy;

		vector<ll> a(n);
		ll sumLen=0, maxLen=0;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			sumLen += a[i];
			maxLen = max(maxLen, a[i]);
		}

		ll minLen = max(0LL, maxLen - (sumLen - maxLen));

		ll dx = qx - px, dy = qy - py;
		unsigned ll dist2 = (unsigned ll)dx*dx + (unsigned ll)dy*dy;
		unsigned ll min2 = (unsigned ll)minLen*minLen;
		unsigned ll max2 = (unsigned ll)sumLen*sumLen;

		if(min2 <= dist2 && dist2 <= max2) 
			cout << "Yes\n";
		else
			cout << "No\n";
	}
    
	return 0;
}

