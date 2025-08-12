#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); i++)
#define fi(i, a, n) for (int i = a; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;
const int maxn = 1e5;
double eps = 1e-9;


int n, k, a[maxn+1], f[maxn][22], g[maxn][22];

int get_min(int l, int r){
	int k = log2(r-l+1);
	return min(f[l][k], f[r-(1<<k)+1][k]);
}

int get_max(int l, int r){
	int k = log2(r-l+1);
	return max(g[l][k], g[r-(1<<k)+1][k]);
}

void preprocess(){
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f[i][0] = g[i][0] = a[i];
	}
	
	for(int  j = 1; (1<<j) <= n; j++){
		for(int i = 1; i + (1 << j) - 1 <= n; i++){
			f[i][j] = min(f[i][j-1], f[i+(1 << (j-1))][j-1]);
			g[i][j] = max(g[i][j-1], g[i+(1 << (j-1))][j-1]);
		}
	}
}

void solve(){
	cin >> n >> k;
	preprocess();
	
	for(int i = k; i <= n; i++){
		cout << get_max(i-k+1, i) << " ";
	}
	cout << "\n";
}

int main() {
	int t; cin >> t;
	while(t--) solve();
    return 0;
}
