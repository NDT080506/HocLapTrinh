#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 1e5;
double eps = 1e-9;


void solve(){
	int n, q; cin >> n >> q;
	
	ll a[n]; fo(i, 0, n) cin >> a[i];
	
	ll pre[n+1];
	pre[0] = 0;
	fi(i, 1, n){
		pre[i] = max({pre[i-1] + a[i-1], pre[i-1], a[i-1]});
	} 
	
	while(q--){
		int l, r; cin >> l >> r;
		
		cout << pre[r] - pre[l-1] << "\n";
	}
}


int main() {
//	freopen("debug_inp.txt", "r", stdin);
	
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
