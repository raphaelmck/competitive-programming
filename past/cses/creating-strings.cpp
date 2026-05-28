#include <bits/stdc++.h>
using namespace std;

string s;
vector<bool> used;
vector<string> ans;

void dfs(string current) {
    if (current.size() == s.size()) {
        ans.push_back(current);
        return;
    }


    for (int i=0; i<s.size(); ++i) {
        if (used[i]) continue;

        if (i>0 && s[i] == s[i-1] && !used[i-1]) continue;

        used[i] = true;
        dfs(current + s[i]);
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    used.assign(s.length(), false);
    sort(s.begin(), s.end());

    dfs("");

    cout << ans.size() << '\n';
    for (string x : ans) {
        cout << x << '\n';
    }

    return 0;
}
