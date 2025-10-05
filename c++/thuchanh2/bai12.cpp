#include <bits/stdc++.h>
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

using ll = long long;
using namespace std;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())

const int mod = (int)1e9 + 7;
const int maxn = (int)1e6;
double eps = 1e-9;

typedef struct nguoi{
	string ten, ns;
	string ngay, thang, nam;
}ds;

bool cmp(const nguoi& a, const nguoi& b){
	if (a.nam == b.nam && a.thang == b.thang && a.ngay != b.ngay) return a.ngay < b.ngay;
	else if (a.nam == b.nam && a.thang != b.thang) return a.thang < b.thang;
	else if (a.nam != b.nam) return a.nam < b.nam;
}

void solve(){
	int n; cin >> n;
	vector<nguoi> ds(n);
	
	fo(i, 0, n){
		cin >> ds[i].ten >> ds[i].ns;
	}
	
	fo(i, 0, n){
		string tmp = ds[i].ns;
		stringstream ss(tmp);
		string token;
		
		int cnt = 1;
		while(getline(ss, token, '/')){
			if (cnt == 1) ds[i].ngay = token;
			else if (cnt == 2) ds[i].thang = token;
			else if (cnt == 3) ds[i].nam = token;
			cnt++;
		}
	}
	
	sort(ds.begin(), ds.end(), cmp);
	cout << ds[n-1].ten << "\n" << ds[0].ten;
	
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}
