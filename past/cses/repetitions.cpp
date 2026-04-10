#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int ans = 1, streak = 1;
    for (int i=1; i<(int)s.length(); ++i) {
        if (s[i] == s[i-1]) streak++;
        else { ans = max(ans, streak); streak = 1; }
    }   
    cout << max(ans, streak) << '\n';
}
