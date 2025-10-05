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
	int n; cin >> n;
	char a[n][3];
	
	fo(i, 0, n) fo(j, 0, 3) cin >> a[i][j];
	
	int ans = 0;
	fo(i, 0, n){
		int cnt1 = 0, cnt0 = 0;
		fo(j, 0, 3){
			if (a[i][j] == '1') cnt1++;
			else cnt0++;
		}
		
		if (cnt1 > cnt0) ans++;
	}
	cout << ans;
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //cin.ignore();
	solve();
	return 0;
}
