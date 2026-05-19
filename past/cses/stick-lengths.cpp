#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    vector<long long> p(n);
    
    for (int i=0; i<n; ++i) cin >> p[i];

    sort(p.begin(), p.end());

    long long median = p[n/2];
    long long ans = 0;

    for (int i=0; i<n; ++i) {
        ans += abs(p[i] - median);
    }

    cout << ans << '\n';

    return 0;
}
