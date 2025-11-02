#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define MAX_N 2

const int mod = (int)1e9 + 7;
const int maxn = (int)1e5;
double eps = 1e-9;

int n, k;
vector<int> tmp;
vector<vector<int>> ans;

void ql(int pos, int len){
	for(int i = pos; i <= n; ++i){
		tmp.push_back(i);
		if (len == k-1){
			ans.push_back(tmp);
		}else{
			ql(i+1, len+1);
		}
		tmp.pop_back();
	}
}

void solve(){ 
	cin >> n >> k;
	vector<int> tohop(k); 
	fo(i, 0, k) cin >> tohop[i];
	
	
	ql(1, 0);
	fo(i, 0, (int)ans.size()){
		int flag = 1;
		fo(j, 0, k){
			if (ans[i][j] != tohop[j]){
				flag = 0;
				break;
			} 
		//	cout << ans[i][j] << " ";
		}
		//cout << "\n"
		if (flag){
			cout << i + 1 << "\n";
			break;
		}
	}
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
	return 0;
}

