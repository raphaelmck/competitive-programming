#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;

    vector<int> children(n);
    for (int i=0; i<n; ++i) cin >> children[i];

    sort(children.begin(), children.end());

    int matched = 0, ans = 0;
    int l = 0, r = n-1;
    while (matched < n) {
        if (children[r] + children[l] <= x) {
            matched += 2;
            l++;
            r--;
        } else {
            matched++;
            r--;
        }
        ans += 1;
    }

    cout << ans << '\n';
}
