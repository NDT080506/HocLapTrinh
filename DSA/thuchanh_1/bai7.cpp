#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 50;
double eps = 1e-9;



void solve(){
	int n, k; cin >> n >> k;
	
	int a[n]; fo(i, 0, n) cin >> a[i];
	multiset<int> se;
	
	fo(i, 0, k) se.insert(a[i]);
	
	cout << *prev(se.end()) << " ";
	for(int i = k; i < n; ++i){
		auto it = se.find(a[i-k]);
		se.erase(it);
		se.insert(a[i]);
		cout << *prev(se.end()) << " ";
	}
}


int main() {
//	freopen("debug_inp.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		solve();
		cout << "\n";	
	}
	
//	solve();
	return 0;
}

