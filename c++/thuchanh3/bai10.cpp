#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

const int mod = (int)1e9 + 7;
const int maxn = (int)1e7;
double eps = 1e-9;

class SinhVien{
	public:
		string msv, hoten, lop, ns;
		float gpa;
	
	public:
		
		void nhap(){
			msv	= "B20DCCN001";
			getline(cin, hoten);
			cin >> lop;
			cin >> ns;
			cin >> gpa;	
		}
		
		void xuat(){
			string tmp = ns;
			stringstream ss(tmp);
			string t;
			
			string res = "";
			int cnt = 0;
			while(getline(ss, t, '/')){
				if (stoi(t) < 10) t = "0" + t;
				res += t;
				if (cnt < 2) res += "/";
				++cnt;
			}
			
			ns = res;
			
			cout << msv << " " << hoten << " " << lop << " " << ns << " ";
			cout << fixed << setprecision(2) << gpa << "\n";
		}
};

void solve(){ 
	SinhVien a;
	a.nhap();
	a.xuat();
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
	return 0;
}

