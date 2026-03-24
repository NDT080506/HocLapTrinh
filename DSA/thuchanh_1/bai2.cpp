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

void in(){
	cout << s << " ";
	for(string x: ans) cout << x << " ";
	cout << "\n";
}

void ql(int pos){
	for(int i = 0; i < n; ++i){
		if (used[i]) continue;
		used[i] = 1;
		ans.push_back(a[i]);
		if (pos == n-2){
			in();
		}else{
			ql(pos+1);
		}
		ans.pop_back();
		used[i] = 0;
	}
}

void solve(){
	cin >> n;
	
	a.resize(n);
	fo(i, 0, n) cin >> a[i];
	cin >> s;
	
	sort(a.begin(), a.end());
	
	fo(i, 0, n){
		if (a[i] == s){
			used[i] = 1;
			break;
		}
	}
	
	ql(0);
}


int main() {
//	freopen("debug_inp.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
//	int t; cin >> t;
//	while(t--) {
//		solve();
//		cout << "\n";	
//	}
	
	solve();
	return 0;
}

