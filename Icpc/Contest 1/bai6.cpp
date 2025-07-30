#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fi(i, n) for (int i = 1; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;

// tinh mod cua mot so nguyen nho va so nguyen lon

ll mod_(ll a, string b){
	ll res = 0;
	for(char ch: b){
		res = (res * 10 + (ch - '0')) % a; 
	}
	return res;
}

// tinh uoc so chung lon nhat cua hai so nguyen nho

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

// tinh uoc so chung cua so nguyen nho va so nguyen lon

ll gcd_large(ll a, string b){
	ll rem = mod_(a, b);
	return gcd(a, rem); 
}

void solve(){
	ll a; string b; cin >> a >> b;
	
	cout << gcd_large(a, b);
}
	
int main(){
	int t; cin >> t;
	while(t--) solve();
	return 0; 
}
