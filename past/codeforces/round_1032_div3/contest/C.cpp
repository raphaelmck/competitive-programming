#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                cin >> a[i][j];
        
        int maxVal = 0, second = 0;
        for(auto &row : a) 
            for(int v : row) {
                if(v > maxVal) {
                    second = maxVal;
                    maxVal = v;
                } else if(v < maxVal && v > second) second = v;
            }

        vector<int> rowCountOfMax(n, 0), colCountOfMax(m, 0);
        vector<int> rowMax(n, 0), colMax(m, 0);
        int totalMaxCount = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                int v = a[i][j];
                if(v==maxVal) {
                    totalMaxCount++;
                    rowCountOfMax[i]++;
                    colCountOfMax[j]++;
                }
                rowMax[i] = max(rowMax[i], v);
                colMax[j] = max(colMax[j], v);
            }
        
        int ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int covered = rowCountOfMax[r] + colCountOfMax[c] - (a[r][c] == maxVal);
                int X = (covered == totalMaxCount ? second : maxVal);
                int H = max(rowMax[r], colMax[c]) - 1;
                ans = min(ans, max(X, H));
            }
        }
        cout << ans << endl;
    }         
    return 0;
}

