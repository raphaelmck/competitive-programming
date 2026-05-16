#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> movies;

    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a});
    }

    sort(movies.begin(), movies.end());

    int total = 0;
    int lastEnd = 0;
    for (auto [end, start] : movies) {
        if (start >= lastEnd) {
            total++;
            lastEnd = end;
        }
    }

    cout << total << '\n';

    return 0;
}
