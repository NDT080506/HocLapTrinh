#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 25;
double eps = 1e-9;

int dp[2][2005][2][2];


void solve(){
	int m, d; cin >> m >> d;
	
	string a, b; cin >> a >> b;
	int n = (int)a.size();
	
	memset(dp, 0, sizeof(dp));
	dp[0][0][1][1] = 1;
	
	fo(i, 0, n){
		int cur = i % 2;
		int next = (i + 1) % 2;
		memset(dp[next], 0, sizeof(dp[next]));
		
		bool even_pos = ((n - 1) % 2 == 0);
		
		fo(rem, 0, m){
			fo(lt, 0, 2){
				fo(ht, 0, 2){
					if (dp[cur][rem][lt][ht] == 0) continue;
					int lower = lt? (a[i] - '0') : 0;
					int upper = ht? (b[i] - '0') : 9;
					
					fi(digit, lower, upper){
						if (even_pos){
							if (digit != d) continue;
						}else{
							if (digit == d) continue;
						}
						
						int next_rem = (rem * 10 + digit) % m;
						int next_lt = lt && (digit == lower);
						int next_ht = ht && (digit == upper);
						
						dp[next][next_rem][next_lt][next_ht] = (dp[next][next_rem][next_lt][next_ht] + dp[cur][rem][lt][ht]) % mod; 
					}
				}
			}
		}
	}
	
	int ans = 0;
	fo(lt, 0, 2){
		fo(ht, 0, 2){
			ans = (ans + dp[n % 2][0][lt][ht]) % mod;
		}
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

