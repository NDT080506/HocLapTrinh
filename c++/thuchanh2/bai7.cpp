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
	int n;
	ll k; 
	cin >> n >> k;
	
	ll a[n+1]; fi(i, 1, n) cin >> a[i];
	
	vector<ll> dp(n+1, 0);
	fi(i, 1, n) dp[i] = dp[i-1] + a[i];
	
	ll mx = -LLONG_MAX;
	int start = -1, end = -1;
	fi(i, k, n){
		ll sum = dp[i] - dp[i-k];
		if (mx < sum){
			mx = sum;
			start = i-k+1;
			end = i;
		}
	}
	
	fi(i, start, end) cout << a[i] << " ";
	cout << "\n";
}

int main() {
    freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //cin.ignore();
	solve();
	return 0;
}
