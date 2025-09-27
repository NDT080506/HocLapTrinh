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



void solve() {
    int n; cin >> n;
    for(int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            cout << i << " " << cnt << "\n";
        }
    }
    if (n > 1) cout << n << " " << 1;
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}*/
