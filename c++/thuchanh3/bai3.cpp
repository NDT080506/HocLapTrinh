#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define MAX_N 2

const int mod = (int)1e9 + 7;
const int maxn = (int)1e6;
double eps = 1e-9;

void solve(){ 
	int p, q, s, t; cin >> p >> q >> s >> t;
	
	vector<int> digits;
	map<ll, int> mp;
	int r = p % q;
	
	int cycle = 0;
	while(1){
		if (r == 0) break;
		if (mp.count(r)){
			cycle = 1;
			break;
		}
		
		mp[r] = digits.size();
		r *= 10;
		digits.push_back(r/q);
		r %= q;
	}
	
	
	int ans = 0;
	while(s < t){
		fo(i, 0, (int)digits.size()){
			ans += digits[i];
			++s;
			if (s > t) break;
		}
		
		if (!cycle) break;
		
	}
	
	cout << ans % q << "\n";
	
}

int main() {
    freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
 	int t; cin >> t;
    while(t--) solve();
	return 0;
}

