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
		cin >> n;
        vector<int> a(n);
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i=0; i<n; ++i) {
            int w; cin >> w; 
            if (w == 0) c0++;
            else if (w == 1) c1++;
            else c2++;
        }

        int pairs = min(c1, c2);
        c0 += pairs;
        c1 -= pairs;
        c2 -= pairs;

        c0 += c1 / 3 + c2 / 3;
        cout << c0 << '\n';
	}
    
	return 0;
}

