#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define MAX_N 2

const int mod = (int)1e9 + 7;
const int maxn = (int)1e7;
double eps = 1e-6;
double diff = 1e-9;

int isPrime[51];
vector<int> prime;

int n;
ll l, r;

void sang(){
	fi(i, 2, n) isPrime[i] = 1;
	for(int i = 2; i * i <= n; ++i){
		if (isPrime[i]){
			for(int j = i * i; j <= n; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	
	fi(i, 2, n) if (isPrime[i]) prime.push_back(i); 
}

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

vector<pair<ll,int>> boiso;
void sinh(int pos, ll boi, int thanhphan){
	if (pos == (int)prime.size()){
		if (boi != 0 && thanhphan != 0){
			boiso.push_back({boi, thanhphan});
		}
		return;
	}
	
	sinh(pos+1, boi, thanhphan);
	if (boi != 0)boi = lcm(prime[pos], boi);
	else boi = prime[pos];
	sinh(pos+1, boi, thanhphan+1);
}

void solve(){ 
	cin >> n >> l >> r;
	
	sang();
	sinh(0, 0, 0);
    sort(boiso.begin(), boiso.end(), [](pair<ll,int>&a, pair<ll,int>&b){
    	if (a.second == b.second) return a.first < b.first;
    	return a.second < b.second;
	});
	
	
	
	ll ans = 0;
	for(auto& it: boiso){
		//cout << it.first << " " << it.second << "\n";
		if (it.first > r) continue;
		//cout << it.first << " " << it.second << "\n";
		int tmp = it.first;
		if (it.second % 2 == 1){
			ans += (r / it.first - (l - 1) / it.first);
		}else{
			ans -= (r / it.first - (l - 1) / it.first);
		}
	}
	cout << ans << "\n";
	
	fi(i, 1, n) isPrime[i] = 0;
	prime.clear();
	boiso.clear();
}

int main() {
    freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
