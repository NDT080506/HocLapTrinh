#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 1;
double eps = 1e-9;



void solve(){
	ll n; cin >> n;
	ll a[n+1]; fi(i, 1, n) cin >> a[i];
	
	ll mx = 0;
	fi(i, 1, n) mx = max(mx, a[i]);
	
	ll ans = 0;
	ll cur = 0;
	
	for(ll i = 1; i <= n; ++i){
		
		if (a[i] == mx){
			++cur;
			ans = max(ans, cur);
		}else cur = 0;
		
	}
	
	cout << ans;
}


int main() {
	freopen("debug_inp.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
//	int t; cin >> t;
//	while(t--) {
//		solve();
//		cout << "\n";	
//	}
	
	solve();
	return 0;
}
