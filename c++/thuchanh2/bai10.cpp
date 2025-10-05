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
	int n, m; cin >> n >> m;
	int mat[n][m];
	int row = 0;
	int col = 0;
	fo(i, 0, n*m){
		int x; cin >> x;
		mat[row][col] = x;
		++col;
		if (col == m){
			col = 0;
			++row;
		}
	}
	
	int ans[n*m];
	int len = 0;
	int top = 0, bottom = n-1, left = 0, right = m-1;
	while(left <= right && top <= bottom){
		for(int i = left; i <= right; ++i) ans[len++] = mat[top][i];
		++top;
		for(int i = top; i <= bottom; ++i) ans[len++] = mat[i][right];
	 	--right;
	 	for(int i = right; i >= left; --i) ans[len++] = mat[bottom][i];
	 	--bottom;
	 	for(int i = bottom; i >= top; --i) ans[len++] = mat[i][left];
	 	++left;
	}
	
	fo(i, 0, n*m) cout << ans[i] << " ";
	cout << "\n";
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    //cin.ignore();
	while(t--) solve();
	return 0;
}
