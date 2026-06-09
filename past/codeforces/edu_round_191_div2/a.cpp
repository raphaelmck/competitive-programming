#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int ceil(int a, int b) {
    return (a+b-1)/b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {
		int n;	
		cin >> n;

		int x, y, z; cin >> x >> y >> z;

		int k;
		if (x*z>=n) {
			k = ceil(n, x);
		} else {
			k = z + ceil(n-x*z, x+10*y);
	
		}
		cout << min(ceil(n, x+y), k) << '\n';
		
	}
    
	return 0;
}