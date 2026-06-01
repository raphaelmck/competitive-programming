#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, a, b; 
        cin >> n >> a >> b;

        bool ok = false;
        if (a+b <= n) {
            if ((a == 0 && b == 0) || (a > 0 && b > 0)) ok = true;
        }

        if (!ok) { cout << "NO\n"; continue; }
        cout << "YES\n";

        vector<int> p1, p2;
        for (int i=1; i<=n; ++i) {
            p1.push_back(i);
        }

        for (int i=a+1; i<=a+b; ++i) p2.push_back(i);
        for (int i=1; i<=a; ++i) p2.push_back(i);
        for (int i=a+b+1; i<=n; ++i) p2.push_back(i);

        for (int i=0; i<n; ++i) cout << p1[i] << ' ';
        cout << '\n';
        for (int i=0; i<n; ++i) cout << p2[i] << ' ';
        cout << '\n';

    }

    return 0;
}
