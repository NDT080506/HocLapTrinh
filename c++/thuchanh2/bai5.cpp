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

int chiahet(string s){
	int res = 0;
	int n = s.size();
	for(int i = 0; i < n; ++i){
		res = (res * 10 + (s[i] - '0')) % 11;
	}	
	
	return (res == 0);
}

void solve(){
	string s; cin >> s;
	
	if (chiahet(s)) cout << "1\n";
	else cout << "0\n";
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
