#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const int mod = (int)1e9 + 7;
const int maxn = (int)1e6;
double eps = 1e-9;

string Plus(string a, string b){
	while((int)a.size() > (int)b.size()) b = "0" + b;
	while((int)b.size() > (int)a.size()) a = "0" + a;
	
	
	int n = (int)a.size();
	int nho = 0;
	string res = "";
	for(int i = n-1; i >= 0; --i){
		int x = a[i] - '0';
		int y = b[i] - '0';
		int t = x + y + nho;
		nho = t/10;
		t %= 10;
		res += (t + '0');
	}
	
	
	if (nho > 0) res += '1';
	reverse(res.begin(), res.end());
	return res;
}

string Minus(string a, string b){
	if ((int)a.size() < (int)b.size() || ((int)a.size() == (int)b.size() && a < b)) swap(a, b);
	
	while((int)a.size() > (int)b.size()) b = "0" + b;
	
	int n = (int)a.size();
	
	int nho = 0;
	string res = "";
	for(int i = n-1; i >= 0; --i){
		int x = a[i] - '0';
		int y = b[i] - '0';
		int h = x - y - nho;
		if (h < 0){
			h += 10;
			nho = 1;
		}else{
			nho = 0;
		}
		
		res += (h + '0');
	}
	
	while((int)res.size() > 1 && res.back() == '0') res.pop_back();
	reverse(res.begin(), res.end());
	
	return res;
}


string karatsuba(string x, string y){
	int n = max(x.size(), y.size());
	if (n == 1){
		return to_string(stoll(x) * stoll(y));
	}
	
	while(x.size() < n) x = "0" + x;
	while(y.size() < n) y = "0" + y;
	
	int m = n/2;
	string a = x.substr(0, n-m);
	string b = x.substr(n-m, m);
	
	string c = y.substr(0, n-m);
	string d = y.substr(n-m, m);
	
	
	string U = karatsuba(a, c);
	string V = karatsuba(b, d);
	string W = karatsuba(Plus(a,b), Plus(c,d));
	string T = Minus(Minus(W,U), V);
	
	fi(i, 1, 2*m) U += "0";
	fi(i, 1, m) T += "0";
	
	string ans = Plus(U,T);
	ans = Plus(ans, V);

	return ans;   
}

void solve() {
	string s1, s2; cin >> s1 >> s2;
	cout << karatsuba(s1, s2);
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

