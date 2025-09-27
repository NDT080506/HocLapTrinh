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

int a[21];
int mark[10];
int n, m;

void in(){
    fo(i, 0, n-1) cout << a[i] << " ";
    cout << m << "\n";
}

void ql(int pos){

    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;
        mark[i] = 1;
        a[pos] = i;
        if (pos == n-2){
            in();
        } else ql(pos+1);
        mark[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    mark[m] = 1;
    ql(0);
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}*/
