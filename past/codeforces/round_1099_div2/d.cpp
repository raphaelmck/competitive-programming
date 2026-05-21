#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

#define INF 2e18

void solve() {
    int n;	
    cin >> n;
    string s; cin >> s;
    vector<ll> a(n+1), c(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) cin >> c[i];

    if (s[0] == '1' && a[1] != c[1]) {
        cout << "NO\n";
        return;
    }

    vector<ll> l(n+1), r(n+1);
    l[1] = r[1] = c[1];

    for (int i=2; i<=n; ++i) {
        if (c[i] <c[i-1]) { cout << "NO\n"; return; }
        ll l1 = (c[i] > c[i-1]) ? c[i] : -INF;
        ll r1 = c[i];
        ll l2 = -INF;
        ll r2 = INF;
        if (s[i-1] == '1') {
            l2 = (l[i-1] == -INF) ? -INF : l[i-1] + a[i];
            r2 = (r[i-1] == INF) ? INF : r[i-1] + a[i];
        }

        l[i] = max(l1, l2);
        r[i] = min(r1, r2);

        if (l[i] > r[i]) {
            cout << "NO\n";
            return;
        }
    }

    vector<ll> b(n+1);
    b[n] = r[n];

    for (int i=n; i>=2; --i) {
        if (s[i-1] == '1') {
            b[i-1] = b[i] - a[i];
        } else {
            b[i-1] = r[i-1];
        }
    }
    b[1] = c[1];
    cout << "YES\n";
    cout << b[1] << " ";
    for (int i=2; i<=n; ++i) {
        cout << b[i] - b[i-1] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int t; cin >> t;
    while (t--) {
		solve();
	}
    
	return 0;
}

