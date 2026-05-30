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
		ll n, x, s;
		cin >> n >> x >> s;
		string u; cin >> u;

		ll emptyTables = x;
		ll eSlots = 0;
		ll eAmbi = 0;
		ll seated = 0;

		for (char c : u) {
			if (c == 'I') {
				if (emptyTables >0) {
					emptyTables--;
					eSlots += s-1;
					seated++;
				}
			} else if (c == 'E') {
				if (eSlots >0) {
					eSlots--;
					seated++;
				} else if (eAmbi >0 && emptyTables>0) {
					eAmbi--;
					emptyTables--;
					eSlots += s-1;
					seated++;
				}
			} else {
				if (eSlots > 0) {
					eSlots--;
					eAmbi++;
					seated++;
				} else if (emptyTables>0) {
					emptyTables--;
					eSlots += s-1;
					seated++;
				}
			}
		}
		cout << seated <<'\n';
	}
    
	return 0;
}

