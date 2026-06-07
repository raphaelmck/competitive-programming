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
        ll n, k;
        cin >> n >> k;

        string a, b;
        cin >> a >> b;

        ll onesA = 0, onesB = 0, onesXor = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == '1') onesA++;
            if (b[i] == '1') onesB++;
            if (a[i] != b[i]) onesXor++;
        }

        ll pow2 = 1LL << k;

        ll cntA, cntB, cntXor;

        if (k % 2 == 1) {
            cntA = cntB = cntXor = (pow2 + 1) / 3;
        } else {
            cntA = cntB = (pow2 + 2) / 3;
            cntXor = (pow2 - 1) / 3;
        }

        auto value = [&](ll ones) -> ll {
            ll zeros = n - ones;
            return ones * zeros;
        };

        ll ans = 0;
        ans += cntA * value(onesA);
        ans += cntB * value(onesB);
        ans += cntXor * value(onesXor);

        cout << ans << '\n';
    }

    return 0;
}