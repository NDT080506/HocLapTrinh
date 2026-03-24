#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 1;
double eps = 1e-9;



void solve(){
	double a, b, c; cin >> a >> b >> c;
	
	double low = 0, high = 1000;
	fo(i, 0, 100){
		double mid = low + (high - low) / 2;
		if (a  * mid * mid * mid  + b * mid > c){
			high = mid;
		}else{
			low = mid;
		}
	}
	
	cout << fixed << setprecision(4) << low;
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
