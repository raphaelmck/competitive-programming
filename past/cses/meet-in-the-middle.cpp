#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> getSums(vector<ll>& a) {
    vector<ll> sums = {0};

    for (ll v : a) {
        int s = sums.size();
        for (int i=0; i<s; ++i) {
            sums.push_back(sums[i] + v);
        }
    }

    return sums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }

    vector<ll> left, right;
    for (int i=0; i<n/2; ++i) {
        left.push_back(a[i]);
    }

    for (int i=n/2; i<n; ++i) {
        right.push_back(a[i]);
    }

    vector<ll> leftSums = getSums(left);
    vector<ll> rightSums = getSums(right);

    sort(rightSums.begin(), rightSums.end());

    ll ans = 0;
    for (ll s : leftSums) {
        ll need = x - s;

        auto l = lower_bound(rightSums.begin(), rightSums.end(), need);
        auto r = upper_bound(rightSums.begin(), rightSums.end(), need);
        ans += r - l;
    }

    cout << ans << '\n';

    return 0;
}
