#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fi(i, n) for (int i = 1; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;


void solve(){
	ll n; cin >> n;
	
	// lap mang fibonacci 
	
	ll fib[93] = {0};
	fib[1] = 1;
	fib[2] = 2;
	int i = 3;
	
	// tinh fibonacci lon nhat nho hon hoac bang n
	
	while(fib[i-1] + fib[i-2] <= n){
		fib[i] = fib[i-1] + fib[i-2];
		i++;
	}
	
	// phan tich n bang tong cac so fibonacci, dap an la so fibonacci nho nhat
	
	ll ans = 1e18;
	for(int k = i-1; k >= 1; k--){
		if (fib[k] <= n){
			ans = min(fib[k], ans);
			n -= fib[k];
		}
	}
	
	cout << ans;
	
}
	
int main(){
	solve();
	return 0; 
}
