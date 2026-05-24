#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> position(n);
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        position[x] = i;
    }

    int ans = 1;
    for (int i=2; i<=n; ++i) {
        if (position[i] < position[i-1]) {
            ans++;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}