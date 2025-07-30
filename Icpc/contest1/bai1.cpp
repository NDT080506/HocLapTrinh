#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fi(i, n) for (int i = 1; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;


void solve(){
	int n; cin >> n;
	
	// mang luu tru cac diem duoc hien trong test case
	vector<pair<int,int>> points(n);
	fo(i,n){
		// toa do x
		cin >> points[i].first;
		//toa do y
		cin >> points[i].second;
	}
	
	int ans = 0;
	
	// loop qua tung truong hop voi ba con tro i, j, k chi vao ba diem khac nha
	// do phuc tap cua thuat toan nay la O(N^3)
	
	for(int i = 0; i < n-2; i++){
		for(int j = i+1; j < n-1; j++){
			for(int k =j+1; k < n; k++){
				
				// thuc hien tinh toan (x1-x2) va (y1 - y2)
				
				ll vecx1 = points[i].first - points[j].first;
				ll vecy1 = points[i].second - points[j].second;
				ll vecx2 = points[k].first - points[j].first;
				ll vecy2 = points[k].second - points[j].second;
				
				// dieu kien de ba diem khong thang hang (x1-x2)/(y1-y2) != (x2-x3)/(y2-y3)
				
				if (vecx1 * vecy2 != vecx2 * vecy1) ans++;
				
			}
		}
	}
	
	cout << ans;
	
}
	
int main(){
	solve();
	return 0; 
}
