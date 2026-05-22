#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();

    unordered_set<char> seen;
    string ans = string(n, '0');

    int j=0;
    for (int i=0; i<n; ++i) {
        if (seen.count(s[i])) {
            seen.erase(s[i]);
            ans[j] = s[i];
            ans[n-j-1] = s[i];
            j++;
        } else {
            seen.insert(s[i]);
        }
    }

    if (seen.size() > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    if (n & 1) ans[n/2] = *seen.begin();

    cout << ans << '\n';

    return 0;
}