#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 1;
double eps = 1e-9;



void solve(){
	int n; cin >> n;
	
	vector<pair<ll,int>> a(n);
	fo(i, 0, n) cin >> a[i].first >> a[i].second;
	
	
	sort(a.begin(), a.end(), [](const pair<ll,int>& b, const pair<ll,int>& c){
		return b.first < c.first;
	});
	
	priority_queue<ll, vector<ll>, greater<ll>> heap;
	
	fo(i, 0, n){
		heap.push(a[i].second);
		
		if (heap.size() > a[i].first){
			heap.pop();
		}
	}
	
	ll ans = 0;
	while(!heap.empty()){
		ans += heap.top();
		heap.pop();
	}
	
	cout << ans;
}


int main() {
	freopen("debug_inp.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
//	int t; cin >> t;
//	while(t--) {
//		solve();
//		cout << "\n";	
//	}
	
	solve();
	return 0;
}
