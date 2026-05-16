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
		int n, x1, x2, k;	
		cin >> n >> x1 >> x2 >> k;


        int inner = abs(x1 - x2);
        int dist = min(inner, n - inner);

        if (n <= 3) cout << 1 << '\n';
        else cout << k + dist << '\n';
	}
    
	return 0;
}

