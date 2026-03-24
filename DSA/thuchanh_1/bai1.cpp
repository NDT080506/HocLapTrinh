#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 25;
double eps = 1e-9;

vector<int> b;
int n, k; 
vector<vector<int>> ans;

void ql(int pos){
	for(int i = 0; i <= 1; ++i){
		b.push_back(i);
		if (pos == n-1){
			ans.push_back(b);
		}else{
			ql(pos+1);
		}
		b.pop_back();
	}
}

void solve(){
	cin >> n >> k;
	
	
	ql(0);
	
	
	for(int i = 0; i < (int)ans.size(); i += k){
		for(int x: ans[i]) cout << x;
		cout << "\n";
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

