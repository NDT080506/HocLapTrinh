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
	int n, q; cin >> n >> q;
	
	int a[n+1]; fi(i, 1, n) a[i] = 0;
	
	while(q--){
		int l, r; cin >> l >> r;
		a[l]++;
		if (r + 1 <= n) a[r+1]--;
	}
	
	
	fi(i, 2, n) a[i] += a[i-1];
	
	fi(i, 1, n){
		if (a[i] % 2 == 0) cout << 0 << " ";
		else cout << 1 << " ";
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
