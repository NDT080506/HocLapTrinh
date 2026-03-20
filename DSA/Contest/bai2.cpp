#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 1e7;
double eps = 1e-9;

void solve(){
	string s; cin >> s;

	int n = s.size();
	if (n == 1){
		if (s == "8"){
			cout << "YES";
			return;
		}else{
			cout << "NO";
			return;
		}
	}
	
	if (n == 2){
		int x = (s[0] - '0') * 10 + (s[1] - '0');
		int y = (s[1] - '0') * 10 + (s[0] - '0');
		
		if (x % 8 == 0 || y % 8 == 0){
			cout << "YES";
		}else{
			cout << "NO";
		}
		return;
	}
	
	int mp[10] = {0};
	fo(i, 0, n) mp[s[i]-'0']++;
	
	for(int i = 104; i <= 992; i+=8){
		int tmp = i;
		int c = tmp % 10; tmp /= 10;
		int b = tmp % 10; tmp /= 10;
		int a = tmp;
		
		if (a == 0 || b == 0 || c == 0) continue;
		
		int res[10]={0};
		res[a]++;
		res[b]++;
		res[c]++;
			
		int ok = 1;
		for(int j = 1; j <= 9; ++j){
			if (mp[j] < res[j]){
				ok = 0;
				break;
			}
		}
		
		if (ok){
			cout << "YES";
			return;
		}
	}
	
	cout << "NO";
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

