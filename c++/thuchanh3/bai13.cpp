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
	int thuc;
	int ao;
}SoPhuc;

SoPhuc binh_phuong_tong(SoPhuc& A, SoPhuc& B){
	
	SoPhuc res;
	int x = A.thuc + B.thuc;
	int y = A.ao + B.ao;
	
	res.thuc = x*x - y*y;
	res.ao = 2*x*y;
	return res;
}

void hien_thi(SoPhuc& C){
	cout << C.thuc << " + " << C.ao << "i\n";
}

void solve(){ 
	SoPhuc A, B;
	int a, b, c, d; cin >> a >> b >> c >> d;
	A.thuc = a, B.thuc = c;
	A.ao = b, B.ao = d;
	
	SoPhuc C = binh_phuong_tong(A, B);
	hien_thi(C);
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    int t; cin >> t;
    while(t--) solve();
	return 0;
}

