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

		int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> Pos; // positions of the 1s, base one
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1')
                Pos.push_back(i+1);
        }

        int m = (int)Pos.size();
        if(m <= k) { // all 1s turned on first turn
            cout << "Alice\n";
            continue;
        }

		// find t in [0,k] st Pos[m-k+t] <= k and Pos[1+t] >= n+1-k 
		// two move win for Alice
		// bin searches find largest j with Pos[j] <= k
        int J1 = int(upper_bound(Pos.begin(), Pos.end(), k) - Pos.begin()) - 1;
		// find smallest j with Pos[j] >= n+1-k
        int J2 = int(lower_bound(Pos.begin(), Pos.end(), n + 1 - k) - Pos.begin());

        // compute the t‑interval, check for conditions
        int R = J1 - (m - k - 1);

        bool alice = false;
        if (J1 >= 0 && J2 < m && J2 <= R) {
            alice = true;
        }

        cout << (alice ? "Alice\n" : "Bob\n");
		
	}
    
	return 0;
}

