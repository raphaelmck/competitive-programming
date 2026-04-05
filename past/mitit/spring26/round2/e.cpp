#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int N, M;
long long vcnt = 0;

int cnt(int a, int b) {
    return __builtin_popcount(a ^ b);
}

bool valid(const vector<int>& arr) {
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] > arr[j]) {
                if (cnt(arr[i], arr[j]) != 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

void gen(int index, vector<int>& current_arr, int max_val) {
    if (index == N) {
        if (valid(current_arr)) {
            vcnt = (vcnt + 1) % MOD;
        }
        return;
    }

    for (int val = 0; val <= max_val; ++val) {
        current_arr.push_back(val);
        gen(index + 1, current_arr, max_val);
        current_arr.pop_back(); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> N >> M) {
        int mx = (1 << M) - 1; 
        
        vector<int> current_arr;
        gen(0, current_arr, mx);
        
        cout << vcnt << "\n";
    }

    return 0;
}
