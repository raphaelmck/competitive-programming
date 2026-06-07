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
		ll n;	
		cin >> n;

		vector<ll> p = { 0,1,2,3,4,5,6,7,8,9,22, 11};

		ll a = p[n%12];
		if (a>n) {
			cout << -1 << '\n';
		} else {
			cout << a << ' '  << n - a << '\n';
		}
		
	}
    
	return 0;
}

