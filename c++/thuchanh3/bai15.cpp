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
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    int ans = 0;
    for(int x11 = 1; x11 < 30; ++x11){
        for(int x12 = 1; x12 < 30; ++x12){
            for(int x21 = 1; x21 < 30; ++x21){
                for(int x22 = 1; x22 < 30; ++x22){
                    int x13 = a-x11-x12;
                    int x23 = b-x21-x22;
                    int x33 = f-x13-x23;
                    int x31 = d-x11-x21;
                    int x32 = e-x12-x22;
                    //int x33 = c-x31-x32;
                    if (x31 + x32 + x33 != c) continue;
                    if (x13 >= 1 && x23 >= 1 && x31 >= 1 && x32 >= 1 && x33 >= 1) ans++;
                }
            }
        }
    }
    cout << ans;
}

int main() {
    freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}*/
