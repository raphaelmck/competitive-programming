#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

vector<int> a;
vector<int> pos;
vector<pair<int, pii>> moves;

void move(int i, int tgt) {
	if (pos[i] == tgt) return;

	int c = pos[i];
	int o = 6 - c - tgt;

	for (int k=i-1; k>=1; --k) {
		if (k <= a[i]) {
			move(k, c);
		} else {
			move(k, o);
		}
	}

	moves.push_back({i, {c, tgt}});
	pos[i] = tgt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {
		int n;
		cin >> n;
		a.resize(n+1);

		bool ok = true;
		for (int i=1; i<=n; ++i) {
			cin >> a[i];
			if (a[i] >= i) ok = false;
		}

		if (!ok) { cout << "NO\n"; continue; }

		pos.assign(n+1, 1);
		moves.clear();

		for (int i=n; i>=1; --i) {
			move(i, 3);
		}

		cout << "YES\n" << moves.size() << '\n';
		for (auto& m : moves) {
			cout << m.first << " " << m.second.first << " " << m.second.second << "\n";
		}
	}
    
	return 0;
}

