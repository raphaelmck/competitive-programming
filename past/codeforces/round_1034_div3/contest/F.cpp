#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int T; cin >> T;
	vector<int> Ns(T);
	int maxN=0;
	for(int i=0; i<T; ++i) {
		cin >> Ns[i];
		maxN = max(maxN, Ns[i]);
	}

	vector<int> spf(maxN+1, 0); // smalled prime factor
	for(int i=2; i<=maxN; ++i) {
		if(spf[i] == 0) {
			for(ll j=i; j<=maxN; j+=i) {
				if(spf[j]==0) spf[j] = i;
			}
		}
	}

	for(int t=0; t<T; ++t) {
		int n=Ns[t];
		vector<int> p(n+1);
		iota(p.begin(), p.end(), 0); 

		for(int i=2; i<=n; ++i) {
			if(spf[i] != i) {
				int j = i / spf[i];
				swap(p[i], p[j]);
			}
		}

		for(int i=1; i<=n; ++i) {
			cout << p[i] << (i==n ? '\n' : ' ');
		}
	}

	return 0;
}

