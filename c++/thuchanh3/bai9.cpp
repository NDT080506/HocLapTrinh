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
	string num1, num2; cin >> num1 >> num2;
	
	if ((int)num1.size() < (int)num2.size() || ((int)num1.size() == (int)num2.size() && num1 < num2)){
		swap(num1, num2);
	}
	
	while((int)num2.size() < (int)num1.size()) num2 = "0" + num2;
	
	int n = num1.size();
	
	//cout << num1 << " " << num2 << "\n";
	
	string ans = "";
	int rem = 0;
	for(int i = n-1; i >= 0; --i){
		int x = num1[i] - '0';
		int y = num2[i] - '0';
		int h = x - y - rem;
		if (h < 0){
			h += 10;
			rem = 1;
		}else{
			rem = 0;
		}
		ans += h + '0';
	}
	
	//while((int)ans.size() > 0 && ans.back() == '0') ans.pop_back();
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
	return 0;
}

