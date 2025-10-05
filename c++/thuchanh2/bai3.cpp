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
	string p;
	cin >> p;
	vector<string> a;
	
	stringstream ss(p);
	string t;
	
	while(getline(ss, t, '.')){
		a.push_back(t);
	}
	
	if (a.size() != 4){
		cout << "NO\n";
		return;
	}
	
	for(string& x: a){
		
		if (x.empty() || !all_of(x.begin(), x.end(), ::isdigit)){
			cout << "NO\n";
			return;
		}
		
		int num = stoi(x);
		
		if (num < 0 || num > 255){
			cout << "NO\n";
			return;
		}
		
		if (to_string(num) != x){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    in.ignore();
	while(t--) solve();
	return 0;
}
