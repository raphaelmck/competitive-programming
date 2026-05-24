#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void generate(int k) {
    if (k == 0) {
        cout << s << '\n';
        return;
    }

    generate(k-1);

    s[n-k] = (s[n-k] == '0' ? '1' : '0');

    generate(k-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    s = string(n, '0');

    generate(n);

    return 0;
}