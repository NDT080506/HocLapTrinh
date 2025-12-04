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

typedef struct{
	string msv, hoten, ten, ho;
	float gpa;
} SinhVien;


bool cmp(const SinhVien& a, const SinhVien& b){
	if (a.gpa != b.gpa) return a.gpa > b.gpa;
	if (a.ten != b.ten) return a.ten < b.ten;
	return a.ho < b.ho;
}

void solve(){ 
	int n; cin >> n;
	vector<SinhVien> ds(n);
	
	fo(i, 0, n){
		cin >> ds[i].msv;
		cin.ignore();
		getline(cin, ds[i].hoten);
		cin >> ds[i].gpa;
	}
	
	fo(i, 0, n){
		string tmp = ds[i].hoten;
		stringstream ss(tmp);
		string t;
		vector<string> s;
		while(ss >> t){
			s.push_back(t);
		}
		
		string ans = "";
		fo(i, 0, (int)s.size()){
			fo(j, 0, (int)s[i].size()) s[i][j] = tolower(s[i][j]);
			s[i][0] = toupper(s[i][0]); 
			ans += s[i];
			if (i != (int)s.size()-1) ans += " "; 
		}
		
		ds[i].hoten = ans;
		
		ds[i].ten = s[(int)s.size()-1];
		string res = "";
		fo(i, 0, (int)s.size() - 1){
			res += s[i];
			if (i != (int)s.size()-2) res += " ";
		}
		ds[i].ho = res;
	}	
	
	sort(ds.begin(), ds.end(), cmp);
	
	fo(i, 0, n){
		cout << ds[i].msv << " " << ds[i].hoten << " " << fixed << setprecision(1) << ds[i].gpa << "\n";
	}
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
	return 0;
}

