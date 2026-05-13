#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> event;

    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        event.push_back({a, 1});
        event.push_back({b, 0});
    }

    sort(event.begin(), event.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    int ans = 0;
    int cur = 0;
    for (auto [time, type] : event) {
        if (type == 1) {
            cur++;
            ans = max(ans, cur);
        } else {
            cur--;
        }
    }

    cout << ans << '\n';
}
