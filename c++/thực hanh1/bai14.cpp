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

string s;
vector<string> ans;
int n;


void ql(int pos){

    for(char i = '0'; i <= '2'; ++i){
        s += i;
        if (pos == n-1){
            ans.push_back(s);
        } else ql(pos+1);
        s.pop_back();
    }
}

void solve() {
    cin >> n;
    ql(0);

    fo(i, 0, (int)ans.size()){
        if (i % 2 == 1) cout << i+1 << ": " << ans[i] << "\n";
    }
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}*/
