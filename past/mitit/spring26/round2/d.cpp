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
		int m; cin >> m;

		vector<int> a(m+1), b(m+1), s(m+1);
		vector<vector<int>> rev(m+1);
		queue<int> q;
		vector<bool> forced(m+1, false);

		for (int i=1; i<=m; ++i) {
			cin >> a[i] >> b[i] >> s[i];
			if (s[i] == -1) {
				forced[i] = true;
				q.push(i);
			} else {
				rev[s[i]].push_back(i);
			}
		}

		while (!q.empty()) {
			int u = q.front(); q.pop();

			for (int v : rev[u]) {
				if (!forced[v]) {
					forced[v] = true;
					q.push(v);
				}
			}
		}

		vector<bool> outForced(n+1, false);
		for (int i=1; i<=m; ++i) {
			if (forced[i]) outForced[a[i]] = true;
		}

		bool possible = false;
		for (int i=1; i<n; ++i) {
			if (!outForced[i]) {
				possible = true;
				break;
			}
		}

		if (possible) cout << "YES\n";
		else cout << "NO\n";
		
	}
    
	return 0;
}

