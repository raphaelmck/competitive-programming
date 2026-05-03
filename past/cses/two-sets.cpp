#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;
    long long sum = n * (n+1) / 2;
    long long half = sum / 2;
    if (sum & 1) { cout << "NO\n"; return 0; }
    cout << "YES\n";
    vector<int> set1, set2;
    for (int i=n; i>=1; --i) {
        if (half != 0) {
            if (half >= i) {
                half -= i;
                set1.push_back(i);
            } else {
                set2.push_back(i);
            }
        } else {
            set2.push_back(i);
        }
    }
    
    cout << set1.size() << '\n';
    for (int x : set1) cout << x << ' ';
    cout << '\n';
    cout << set2.size() << '\n';
    for (int x : set2) cout << x << ' ';
    cout << '\n';
    
    return 0;
}
