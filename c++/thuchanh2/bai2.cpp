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

int check(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o');
}

void solve(){
	string s;
	getline(cin, s);
	
	stringstream ss(s);
	
	string t;
	int ans = 0;
	while(ss >> t){
		if (check(t[0]) && (int)t.size() > 3) ans++;
	}	
	cout << ans << "\n";
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	solve();
	return 0;
}
