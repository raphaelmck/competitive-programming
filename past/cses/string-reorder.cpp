#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    int n = s.size();
    vector<int> cnt(26, 0);

    for (char c : s) cnt[c - 'A']++;

    if (*max_element(cnt.begin(), cnt.end()) > (n+1)/2) { cout << -1 << '\n'; return 0; }

    string ans;
    int prev = -1;
    for (int pos=0; pos<n; ++pos) {
        int rem = n-pos-1;

        int mx1 = -1, mx2 = -1, mxChar = -1;
        for (int c=0; c<26; ++c) {
            if (cnt[c] > mx1) {
                mx2 = mx1;
                mx1 = cnt[c];
                mxChar = c;
            } else if (cnt[c] > mx2) {
                mx2 = cnt[c];
            }
        }

        int chosen = -1;

        for (int c=0; c<26; ++c) {
            if (cnt[c] == 0) continue;
            if (c == prev) continue;

            int sameCharLeft = cnt[c] - 1;
            int otherMax = (c == mxChar ? mx2 : mx1);
            if (sameCharLeft <= rem/2 && otherMax <= (rem+1)/2) {
                chosen = c;
                break;
            }
        }

        if (chosen == -1) { cout << -1 << '\n'; return 0; }

        ans.push_back(char('A' + chosen));
        cnt[chosen]--;
        prev = chosen;
    }

    cout << ans << '\n';

    return 0;
}