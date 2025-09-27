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


void solve() {
    string a; cin >> a;
    string b; cin >> b;

    int n = (int)a.size();
    int m = (int)b.size();

    fo(i, 0, n){
        string tmp = a.substr(i, m);
        if (tmp == b){
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}*/
