#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;

    while (q--) {
        long long k; cin >> k;
        long long len = 1, start = 1;

        while (true) {
            __int128 numbers = 9LL * start;
            __int128 blockDigits = numbers * len;

            if ((__int128)k > blockDigits) {
                k -= (long long)blockDigits;
                len++;
                start *= 10;
            } else {
                break;
            }
        }

        long long index = (k-1) / len;
        long long digitIndex = (k-1) % len;

        long long num = start + index;
        string s = to_string(num);

        cout << s[digitIndex] << '\n';
    }

    return 0;
}