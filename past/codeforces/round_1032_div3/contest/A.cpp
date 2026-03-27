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
		int n, s;
		cin >> n >> s;

		vector<int> x(n);

		for(int i=0; i<n; ++i) {
			cin >> x[i];
		}

		int L = x.front();
		int R = x.back();
		cout << min(abs(s - L), abs(s - R)) + R - L << endl;
	}

       	 return 0;
}

