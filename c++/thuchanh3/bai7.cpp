#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

const int mod = (int)1e9 + 7;
const int maxn = (int)1e7;
double eps = 1e-9;

int dp[maxn+1];
int diff[maxn+1];

void solve(){ 
	int n; cin >> n;
	
	// khoi tao
	map<int, int> mp;
	vector<pair<int,int>> a(n); 
		
	fo(i, 0, n){
		cin >> a[i].first >> a[i].second;
		mp.insert({a[i].first, -1});
		mp.insert({a[i].second, -1});	
	}
	
	int q; cin >> q;
	vector<int> b(q);
	fo(i, 0, q){
		cin >> b[i];
		mp.insert({b[i], -1});
		
	}
	
	int len = 1;
	for(auto& it: mp){
		it.second = len;
		++len;
	}
	
	// tinh toan
	fo(i, 0, n){ 
		int u = mp[a[i].first];
		int v = mp[a[i].second];
		
		dp[u]++;
		dp[v+1]--;
	}
	
	fi(i, 1, len){
		diff[i] = diff[i-1] + dp[i];
	}
	
	fo(i, 0, q){
		int idx = mp[b[i]];
		cout << diff[idx] << "\n";
	}
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
	return 0;
}

