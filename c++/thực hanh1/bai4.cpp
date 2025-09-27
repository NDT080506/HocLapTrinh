/*#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())

const int mod = (int)1e9 + 7;
const int maxn = (int)1e7;
double eps = 1e-9;

int isPrime[maxn+1];


void sang(){
    fi(i, 2, maxn) isPrime[i] = 1;
    for(int i = 2; i * i <= maxn; ++i){
        if (isPrime[i]){
            for(int j = i*i; j <= maxn; j +=i){
                isPrime[j] = 0;
            }
        }
    }
}

void solve() {
    ll n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= sqrt(n); ++i){
        if (isPrime[i] && i * i <= n){
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sang();
    int t; cin >> t;
    while(t--) solve();
	return 0;
}*/
