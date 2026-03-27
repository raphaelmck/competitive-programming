#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, m; 
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<m; ++i) cin >> b[i];

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			dp[i+1][j+1] = (a[i] == b[j]) ? dp[i][j] + 1 : max(dp[i+1][j], dp[i][j+1]);
		}
	}
	cout << dp[n][m] << '\n';

	int i = n, j = m;
	vector<int> lcs;
	lcs.reserve(dp[n][m]);
	while (i > 0 && j > 0) {
		if (a[i-1] == b[j-1]) {
			lcs.push_back(a[i-1]);
			--i; --j;
		} else if (dp[i-1][j] >= dp[i][j-1]) {
			--i;
		} else {
			--j;
		}
	}
	reverse(lcs.begin(), lcs.end());

	for (int i=0; i<(int)lcs.size(); ++i) cout << lcs[i] << (i==(int)lcs.size()-1 ? '\n' : ' ');
}
