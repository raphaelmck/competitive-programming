
#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (a[i] < b[j] - k) {
            ++i;
        } else if (a[i] > b[j] + k) {
            ++j;
        } else {
            ans++; j++; i++;
        }
    }
    
    cout << ans << '\n';

    return 0;
}
