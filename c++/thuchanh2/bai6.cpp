#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())

const int mod = (int)1e9 + 7;
const int maxn = (int)1e6;
double eps = 1e-9;


void solve(){
	int n; cin >> n;
	int a[n]; fo(i, 0, n) cin >> a[i];
	
	sort(a, a + n);
	int mn = INT_MAX;
	fo(i, 1, n){
		mn = min(a[i] - a[i-1], mn);
	}
	cout << mn << "\n";
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    //cin.ignore();
	while(t--) solve();
	return 0;
}
