#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define MAX_N 2

const int mod = (int)1e9 + 7;
const int maxn = (int)1e6;
double eps = 1e-9;


int check(string& s){
	int mx1 = 0, mx2 = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		mx1 = max(mx1, s[i] - '0');
	}
	
	//cout << mx1 << " ";
	int flag = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		if (s[i] - '0' > mx2){
			if (s[i] - '0' == mx1 && !flag) flag = 1;
			else mx2 = s[i] - '0';
		}
	}
	//cout << mx2 << " ";
	return mx2;
}

ll dp[maxn+1];
void preprocess(){
	dp[10] = 0;
	fi(i, 11, maxn){
		string tmp = to_string(i);
		int d = check(tmp);
		dp[i] = dp[i-1] + d;
	}
}

void solve(){ 
	int l, r; cin >> l >> r;
	int ans = dp[r] - dp[l-1];
	
	cout << ans << "\n";
}

int main() {
    freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    preprocess();
    int t; cin >> t;
    while(t--) solve();
	return 0;
}

