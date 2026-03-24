#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 50;
double eps = 1e-9;

int fib[maxn];
int a[maxn];

void init(){
	fib[0] = 1;
	fib[1] = 1;
	a[0] = 1;
	a[1] = 0;
	
	fi(i, 2, 45){
		fib[i] = fib[i-1] + fib[i-2];
		a[i] = a[i-1] + a[i-2]; 
	}
}

int dq(int n, int k){
	if (n == 0) return 1;
	if (n == 1) return 0;
	
	int cnt = 0;
	if (k <= fib[n-1]){
		cnt += dq(n-1, k);
	}else{
		cnt += dq(n-2, k-fib[n-1]) + a[n-1];
	}
	return cnt;
}

void solve(){
	int n, k; cin >> n >> k;
	
	cout << dq(n, k);			
}


int main() {
//	freopen("debug_inp.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	init();
	int t; cin >> t;
	while(t--) {
		solve();
		cout << "\n";	
	}
	
//	solve();
	return 0;
}

