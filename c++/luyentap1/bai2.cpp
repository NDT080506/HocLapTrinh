#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define MAX_N 2

const int mod = (int)1e9 + 7;
const int maxn = (int)1e7;
double eps = 1e-6;
double diff = 1e-9;

int n, base; 

struct Matrix{
	int mat[MAX_N][MAX_N];
};

int mulmod(int a, int b){
	int ans = 0;
	a %= base;
	while(b > 0){
		if (b & 1) ans = ans + a % base;
		a = a + a % base;
		b >>= 1;
	}
	return ans;
}

Matrix operator*(Matrix a, Matrix b){
	Matrix ans;
	for(int i = 0; i < MAX_N; ++i){
		for(int j = 0; j < MAX_N; ++j){
			ans.mat[i][j] = 0;
			for(int k = 0; k < MAX_N; k++){
				ans.mat[i][j] += mulmod(a.mat[i][k], b.mat[k][j]);
			}
		}
	}
	return ans;
}

Matrix matpow(Matrix base, int p){
	if (p == 1) return base;
	Matrix tmp = matpow(base, p/2);
	if (p % 2 == 0) return tmp * tmp;
	else return tmp * tmp * base;
}

void solve(){
	cin >> n >> base;
	
	Matrix ans;
	ans.mat[0][0] = 1;
	ans.mat[0][1] = 1;
	ans.mat[1][0] = 1;
	ans.mat[1][1] = 0;
	
	Matrix res = matpow(ans, n);
	long long Fn = (res.mat[1][0] * 1 + res.mat[1][1] * 1) % base;
	cout << Fn << "\n";
}

int main() {
    freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

