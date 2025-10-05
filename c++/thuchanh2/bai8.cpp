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
	int n,m; cin >> n >> m;
	int a[n][m];
	fo(i, 0, n) fo(j, 0, m) cin >> a[i][j];
	
	vector<int> res;	
	fo(k, 0, n*m-1){
		vector<int> tmp;
		fo(i, 0, n){
			int j = k-i;
			if (j >= 0 && j < m){
				tmp.push_back(a[i][j]);
			}
		}
		
		if (k % 2 == 0) reverse(tmp.begin(), tmp.end());
		res.insert(res.end(), tmp.begin(), tmp.end());
	}
	
	fo(i, 0, (int)res.size()){
		cout << res[i] << " ";
	}
	cout << "\n";
}

int main() {
	//freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

