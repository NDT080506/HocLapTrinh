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
vector<int> prime;

void sang(){
    fi(i, 2, maxn) isPrime[i] = 1;
    for(int i = 2; i * i <= maxn; ++i){
        if (isPrime[i]){
            for(int j = i*i; j <= maxn; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    fi(i, 2, maxn){
        if (isPrime[i]) prime.push_back(i);
    }
}

void solve() {
    ll n; cin >> n;

    vector<pair<int,int>> a;
    for(int i = 0; i < (int)prime.size(); ++i){
        if (n % prime[i] == 0){
            int cnt = 0;
            while(n % prime[i] == 0){
                n /= prime[i];
                cnt++;
            }
            a.push_back({prime[i], cnt});
        }
    }
    if (n > 1) a.push_back({n, 1});
    sort(a.begin(), a.end(), [](pair<int,int>& b, pair<int,int>& c){
        if (b.first == c.first) return b.second < c.second;
        return b.first < c.first;
    });

    fo(i, 0, (int)a.size()){
        cout << a[i].first << " " << a[i].second << "\n";
    }
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
