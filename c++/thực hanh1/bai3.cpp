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

int isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if (n % i == 0) return 0;
    }
    return n > 1;
}

void hamtang(int len, int currsum, int last_digit, int& cnt){
    if (len == 0){
        if (isPrime(currsum)){
            cnt++;;
        }
        return;
    }

    for(int i = last_digit+1; i <= 9; ++i){
        hamtang(len-1, currsum * 10 + i, i, cnt);
    }
}

void hamgiam(int len, int currsum, int last_digit, int& cnt){
    if (len == 0){
        if (isPrime(currsum)){
            cnt++;;
        }
        return;
    }

    for(int i = last_digit-1; i >= 0; --i){
        hamgiam(len-1, currsum * 10 + i, i, cnt);
    }
}

void solve() {
    int n; cin >> n;
    int cnt = 0;

    for(int i = 1; i <= 9; i++){
        hamtang(n-1, i, i, cnt);
        hamgiam(n-1, i, i, cnt);
    }
    cout << cnt << "\n";
}

int main() {
    freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)solve();
	return 0;
}*/
