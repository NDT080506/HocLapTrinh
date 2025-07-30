#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fi(i, n) for (int i = 1; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;


void solve(){
	int a, b; cin >> a >> b;
	
	// bang thoi thi khong xet nua
	
	if (a == b){
		cout << 0 << "\n";
		return;
	}	
	int c = abs(a-b);
	
	int d = 0;
	int sum = 0;
	
	// ta co khoang cach ban dau la c = |a - b|
	// voi hai so a và b ta cong xen ke hai so Sum = d*(d+1)/2
	// Dieu kien de hai so bang nhau:
	//           Sum >= c de lap day khoang cach giua hai so
	//           (Sum - c) la chan de cac so duoc cong deu vao hai so
	
	
	while(1){
		d++;
		sum += d;
		if (sum >= c && (sum - c) % 2 == 0){
			cout << d << "\n";
			return;
		}
	}
	
	
}
	
int main(){
	int t; cin >> t;
	while(t--) solve();
	return 0; 
}
