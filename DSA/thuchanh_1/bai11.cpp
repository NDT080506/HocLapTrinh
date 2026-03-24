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

int nt[maxn+1];

void sang(){
	
	for(int i = 2; i <= maxn; ++i){
		if (nt[i] != 0) continue;
		for(int j = i; j <= maxn; j += i){
			nt[j] = i;
		}
	}
}

void solve(){
	int l, r; cin >> l >> r;
	
	int ans = 0;
	fi(i, l, r) ans += nt[i];
	cout << ans;
}


int main() {
//	freopen("debug_inp.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	sang();
	int t; cin >> t;
	while(t--) {
		solve();
		cout << "\n";	
	}
	
//	solve();
	return 0;
}
