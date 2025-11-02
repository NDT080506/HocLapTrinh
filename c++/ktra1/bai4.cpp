#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define MAX_N 2

const int mod = (int)1e9 + 7;
const int maxn = (int)1e5;
double eps = 1e-9;

int n;
string s;
vector<string> ans;


void ql(int pos){
	if (pos >= n/2) return;
	for(char i = '0'; i <= '1'; ++i){
		s += i;
		string tmp = s;
		reverse(tmp.begin(), tmp.end());
		ans.push_back(s + tmp);
		ql(pos+1);
		s.pop_back();
	}
}

void solve(){ 
	cin >> n;
	ql(0);
	sort(ans.begin(), ans.end(), [](string& a, string& b){
		if ((int)a.size() != (int)b.size()) return a.size() < b.size();
		return a < b;
	});
	fo(i, 0, (int)ans.size()){
		if (i + 1 < (int)ans.size()){
			if (ans[i] != ans[i+1]) cout << ans[i] << " ";
		}
	}
	cout << "\n";
}

int main() {
    freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
	return 0;
}

