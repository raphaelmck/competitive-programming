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

		vector<ll> a(n);
		for (int i=0; i<n; ++i) cin >> a[i];

		map<ll, vector<pii>> runs;
		for (int i=0; i<n;) {
			int j=i;
			while (j<n && a[j] == a[i]) j++;
			runs[a[i]].push_back({i, j-1});
			i=j;
		}

		vector<ll> bad;
		for (auto& [v, b] : runs) {
			if (b.size()>1) bad.push_back(v);
		}
		if (bad.empty()) { cout << "YES\n"; continue;}
		if (bad.size() >2) { cout << "NO\n"; continue;}

		bool ok=true;
		for (ll x : bad) {
			if (runs[x].size()>3) ok = false;
		}
		if (!ok) {cout << "NO\n"; continue;}

		vector<int> cand;
		for (ll x : bad) {
			for (auto [l, r] : runs[x]) {
				cand.push_back(l);
				cand.push_back(r);
				if (0<=l-1) cand.push_back(l-1);
				if (r+1<n) cand.push_back(r+1);
			}
		}

		sort(cand.begin(), cand.end());
		cand.erase(unique(cand.begin(), cand.end()), cand.end());

		auto check = [&](vector<ll>& a, int x, int y) {
			swap(a[x], a[y]);
			set<ll> seen;

			ll prev = -1;

			for (int i=0; i<n; ++i) {
				if (i==0 || a[i] != prev) {
					if (seen.count(a[i])) {
						swap(a[x], a[y]);
						return false;
					}
					seen.insert(a[i]);
				}
				prev = a[i];
			}

			swap(a[x], a[y]);
			return true;
		};

		ok = false;
		for (int i=0; i<cand.size(); ++i) {
			for (int j=i+1; j<cand.size(); ++j) {
				if (check(a, cand[i], cand[j])) {
					ok = true;
					break;
				}
			}
			if (ok) break;
		}

		cout << (ok ? "YES\n" : "NO\n");
	}
    
	return 0;
}

