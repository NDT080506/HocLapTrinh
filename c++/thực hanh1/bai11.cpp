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
    int n, m; cin >> n >> m;
    ll a[n]; fo(i, 0, n) cin >> a[i];
    ll b[m]; fo(i, 0, m) cin >> b[i];

    ll mx = *max_element(a, a+n);
    ll mn = *min_element(b,b+m);

    ll ans = mx * mn;
    cout << ans << "\n";
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)solve();
	return 0;
}*/
