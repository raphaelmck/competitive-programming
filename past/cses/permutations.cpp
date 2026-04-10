#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n == 1) { cout << 1 << '\n'; return 0; }
    if (n <= 3) { cout << "NO SOLUTION" << '\n'; return 0; }
    if (n == 4) { cout << "3 1 4 2" << '\n'; return 0; }
    int start = n & 1 ? n - 1 : n;
    for (int i=start; i>0; i-=2) cout << i << ' ';
    start = n & 1 ? n : n - 1;
    for (int i=start; i>0; i-=2) cout << i << ' ';
    cout << '\n';
}
