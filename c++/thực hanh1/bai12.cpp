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

vector<int> bi;
int n, k;
vector<vector<int>> ans;


void ql(int pos, int last_digit){

    for(int i = last_digit; i <= n; i++){
        bi.push_back(i);
        if (pos == k-1){
            ans.push_back(bi);
        } else ql(pos+1, i+1);
        bi.pop_back();
    }
}

void solve() {
    cin >> n >> k;
    bi.clear();
    ans.clear();
    ql(0, 1);

    for(int i = (int)ans.size()-1; i >= 0; i--){
        for(int x: ans[i]) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    //freopen("debug_inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)solve();
	return 0;
}*/
