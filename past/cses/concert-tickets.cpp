#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    multiset<int> tickets;

    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        tickets.insert(x);
    }

    for (int i=0; i<m; ++i) {
        int ask; cin >> ask;
        auto it = tickets.upper_bound(ask);

        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}
