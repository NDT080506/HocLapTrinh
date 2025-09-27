/*#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())

const int mod = (int)1e9 + 7;
const int maxn = (int)2e5;
double eps = 1e-9;

int isPrime(int a){
    for(int i = 2; i * i <= a; ++i){
        if (a % i == 0) return 0;
    }
    return a > 1;
}

void solve() {
    int n,m; cin >> m >> n;

    fi(i, m, n){
        if (isPrime(i)) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
	return 0;
}*/
