#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const int mod = 100;
const int maxn = 2;
double eps = 1e-9;

struct Matrix{
	ll mat[maxn][maxn];
};

ll mulmod(ll a, ll b){
	ll ans = 0;
	a %= mod;
	b %= mod;
	
	while(b > 0){
		if (b & 1) ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

Matrix operator* (Matrix A, Matrix B){
	Matrix ans;
	fo(i, 0, maxn){
		fo(j, 0, maxn){
			ans.mat[i][j] = 0;
			fo(k, 0, maxn){
				ans.mat[i][j] += mulmod(A.mat[i][k], B.mat[k][j]);
			}
		}
	}
	
	return ans; 
}

Matrix matpow(Matrix base, ll n){
	Matrix r = {{{1, 0}, {0, 1}}};
    while (n) {
        if (n & 1) r = r * base;
        base = base * base;
        n >>= 1;
    }
    return r;
}


void solve(){
	ll n; cin >> n;
	
	Matrix ans;
	ans.mat[0][0] = 2;
	ans.mat[0][1] = 3;
	ans.mat[1][0] = 1;
	ans.mat[1][1] = 2;
	
	Matrix res = matpow(ans, n-1);
	
	ll a = (res.mat[0][0] * 4 + res.mat[0][1] * 2) % mod;
	
	a = (a - 1 + mod) % mod;
	if (a < 10) cout << "0" << a;
	else cout << a;
	
	
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
