#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 1e7;
double eps = 1e-9;

int n, k;
vector<string> a(20);
set<string> ans;

void ql(int pos, int cnt, string s){
	
	if (cnt == k){
		ans.insert(s);
		return;
	}
	
	if (pos >= n){
		return;
	}
	
	ql(pos+1, cnt+1, s + a[pos]);
	ql(pos+1, cnt, s);
}

void solve(){
	cin >> n >> k;
	
	fo(i, 0, n) cin >> a[i];
	
	
	ql(0, 0, "");
	
	
	for(auto s: ans){
		cout << s << "\n";
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

