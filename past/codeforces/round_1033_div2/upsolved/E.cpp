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

		ll n, k;
		cin >> n >> k;

		vector<ll> a(n, 0);
		ll sumA=0;
		for(ll i=0; i<n; ++i) {
			cin >> a[i];
			sumA+=a[i];
		}

		sort(a.begin(), a.end());

		ll l=a[0];
		ll r=(sumA + n + 1) / n + 1; // int ceil of the average lane size

		while(r-l>1) {
			ll mid=(l+r)/2;

			ll req=0, exc=0;
			for(ll i=0; i<n; ++i) {
				req+=max<ll>(0, mid-a[i]);
				exc+=max<ll>(0, a[i]-mid-k);
			}
			if(req>exc) r=mid;
			else l=mid;
		}

		ll req=0, exc=0, reqs=0, excs=0, ans=0;
		for(ll i=0; i<n; ++i) {
			if(a[i] <= l) {
				++reqs;
				req+=l-a[i];
				a[i]=l;
			}
			if(a[i] >= l+k+1) {
				++excs;
				exc+=a[i]-l-k;
				a[i]=l+k;
			}
		}

		exc-=req;
		for(ll i=0; i < min<ll>(excs, exc); ++i) a[n-1-i]++;

		exc-=excs;
		for(ll i=0; i<exc; ++i) {
			a[i]++;
			req++;
		}
		ans+= req * k;
		for(ll i=0; i<n; ++i) ans += (a[i] * (a[i]+1)) / 2;
		
		cout << ans << endl;
	}
    
	return 0;
}

