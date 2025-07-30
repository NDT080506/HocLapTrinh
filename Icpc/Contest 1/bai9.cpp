#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fi(i, n) for (int i = 1; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;

// tinh so bac cua so nguyen to p cua n! 

ll bac(int n, int p){
	ll ans = 0;
	for(int i = p; i <= n; i*= p){
		ans += (n / i);
	}
	return ans;
}

// kiem tra so nguyen to

int nt(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return 0;
	}
	return n > 1;
}

void solve(){
	int n, k;
	
	while(cin >> n && cin >> k){
		ll ans = 1;
		for(int i = 1; i <= n; i++){
			
			// ta tinh uoc cua to hop C(n,k) bang cac tinh tich cac tong cua (mi + 1)
			// voi mi la so bac cua cac uoc so nguyen so
			// uoc so nguyen to <= N
			
			// to hop C(n,k) co cong thuc n!/ ((n-k)! * k!), ta tinh bac cua chung va tru cho nhau
			// lay so bac cua tu tru cho so bac cua mau
			
			if(nt(i)){
				ll d = bac(n,i) - bac(n-k,i) - bac(k,i);
				ans *= (d + 1);
			} 
		}
		
		cout << ans << "\n";
	}
}
	
int main(){
	solve();
	return 0; 
}
