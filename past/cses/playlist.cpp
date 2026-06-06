#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n);
    vector<int> vals;

    for (int i=0; i<n; ++i) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<int> last_seen(vals.size(), -1);

    int l=0, ans=0;
    for (int r=0; r<n; ++r) {
        int k = lower_bound(vals.begin(), vals.end(), a[r]) - vals.begin();

        if (last_seen[k] != -1) l = max(l, last_seen[k]+1);

        last_seen[k] = r;
        ans = max(ans, r-l+1);
    }

    cout << ans << '\n';

    return 0;
}