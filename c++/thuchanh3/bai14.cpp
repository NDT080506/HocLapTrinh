#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define MAX_N 2

const int mod = (int)1e9 + 7;
const int maxn = (int)1e6;
double eps = 1e-9;

void solve(){ 
	int n; cin >> n;
	int a[n]; fo(i, 0, n) cin >> a[i];
	
	int nhon = 0, vuong = 0, tu = 0;
	fo(i, 0, n-2){
		fo(j, i+1, n-1){
			int left = j+1, right = n-1;
			while(left <= right){
				int mid = left + (right - left) / 2;
				if (a[i] + a[j] > a[mid]){
					left = mid + 1;
				}else{
					right = mid - 1;
				}
			}
			
			if (right <= j) continue;
			
			ll x = a[i] * a[i], y = a[j] * a[j];
			int l = j+1, r = right;
			int ans1= -1, ans2 = -1;
			while(l <= r){
				int m = l + (r-l) / 2;
				if (x + y > a[m] * a[m]){
					ans1 = m;
					l = m + 1;
				}else{
					r = m - 1;
				}
			}
			
			l = j+1, r = right;
			while(l <= r){
				int m = l + (r-l) / 2;
				if (x + y < a[m] * a[m]){
					ans2 = m;
					r = m - 1;
				}else{
					l = m + 1;
				}
			}
			
			if (ans1 != -1) nhon += ans1 - j;
			if (ans1 != -1 && ans2 != -1) vuong += ans2 - ans1;
			
			if (ans2 != -1){
				if (ans1 != -1){
					tu += ans2 - (ans2 - ans1) - j;
				}else{
					tu += ans2 - j;
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
 
 	solve();
	return 0;
}

