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

    vector<pair<int,int>> a(n);
    fo(i, 0, n){
        cin >> a[i].first;
        cin >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<int,int>& b, pair<int,int>& c){
        return b.first < c.first;
    });

    int ans = 0;

    fo(i, 0, n){
        if (m <= a[i].second){
            ans += a[i].first * m;
            break;
        }else{
            m -= a[i].second;
            ans += a[i].first * a[i].second;
        }
    }
    cout << ans;
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}*/
