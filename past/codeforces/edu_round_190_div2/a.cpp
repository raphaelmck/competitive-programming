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
		ll n, a, b;	
		cin >> n >> a >> b;

        ll c1 = a*n;
        ll c2 = (n/3) * b + (n%3) * a;
        ll c3 = ((n+2)/3) * b;

        cout << min({c1, c2, c3}) << '\n';
	}
    
	return 0;
}

