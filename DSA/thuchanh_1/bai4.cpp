#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 25;
double eps = 1e-9;

vector<string> a;
string s;
int n;
vector<string> ans;
int used[maxn];


void solve(){
	ll p; cin >> p;
	
	if (p == 1){
		cout << 1;
		return;
	}
	
	stack<ll> st;
	for(ll i = 9; i >= 2; --i){
		if (p % i == 0){
			while(p % i == 0){
				st.push(i);
				p /= i;
			}
		}
	}
	
	if (p > 1) cout << -1;
	else if (p == 1){
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
	}
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

