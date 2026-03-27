#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T;
    
    while(T--){
        int n; 
        cin >> n;
        vector<int> a(n), b(n);
        
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        vector<pair<int,int>> ops;
        
        // Step 1: Ensure a[i] < b[i] for all i by swapping if needed
        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) {
                ops.emplace_back(3, i + 1);
                swap(a[i], b[i]);
            }
        }
        
        // Step 2: Sort array a using bubble sort
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(a[j] > a[j + 1]) {
                    ops.emplace_back(1, j + 1);
                    swap(a[j], a[j + 1]);
                }
            }
        }
        
        // Step 3: Sort array b using bubble sort
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(b[j] > b[j + 1]) {
                    ops.emplace_back(2, j + 1);
                    swap(b[j], b[j + 1]);
                }
            }
        }
        
        cout << ops.size() << "\n";
        for(auto &p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    
    return 0;
}
