#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 1e5;
double eps = 1e-9;


void solve(){
	int n; cin >> n;
	ll a[n]; fo(i, 0, n) cin >> a[i];
	
	sort(a, a + n);
	
	ll tu = 0, nhon = 0, vuong = 0;
	
	fo(i, 0, n-2){
		fo(j, i+1, n-1){
			ll left = j+1, right = n-1;
			ll idx = -1;
			while(left <= right){
				ll mid = left + (right - left) / 2;
				if (a[i] + a[j] > a[mid]){
					idx = mid;
					left = mid + 1;
				}else{
					right = mid - 1;
				}
			}
			
			if (idx == -1) continue;
			
			ll sum = a[i]*a[i] + a[j]*a[j];
			
			int left1 = j+1, right1 = idx, pos = idx+1;
			while(left1 <= right1){
				int mid = left1 + (right1 - left1) / 2;
				if (a[mid] * a[mid] >= sum){
					pos = mid;
					right1 = mid - 1;
				}else{
					left1 = mid + 1;
				}
			}
			
			nhon += (pos - (j+1));
			
			if (pos <= idx && a[pos] * a[pos] == sum) ++vuong;
			
			if (pos <= idx){
				if (a[pos] * a[pos] == sum){
					tu += (idx - pos);
				} else{
					tu += (idx - pos + 1);
				}
			}
		}
	}
	
	cout << nhon << " " << vuong << " " << tu;
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
