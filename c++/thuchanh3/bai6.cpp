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


void solve(){ 
	string s; cin >> s;
	
	int l = 0, r = (int)s.size()-1;
	int flag = 1;
	while(l <= r){
		if (s[l] != s[r]){
			flag = 0;
			break;
		}
		++l;
		--r;
	}
	
	if (!flag){
		cout << "NO\n";
		return;
	}
	
	int ans = 0;
	fo(i, 0, (int)s.size()){
		ans += s[i] - '0';
	}
	
	if (ans % 10 == 0){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
	return 0;
}

