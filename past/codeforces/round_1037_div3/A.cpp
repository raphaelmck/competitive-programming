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
        string x;
        cin >> x;
        sort(x.begin(), x.end());
        cout << (x[0] - '0') << "\n";
	}
    
	return 0;
}

