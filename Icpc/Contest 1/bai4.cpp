#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fi(i, n) for (int i = 1; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;


void solve(){
	int n; cin >> n;
	
	// thiet lap mang chua cac phan tu
	int a[n];
	
	// thiet lap mang mau
	int mau[n];
	
	fo(i,n){
		cin >> a[i];
		mau[i] = -1;
	};
	
	// so luong mau it nhat de to mau day
	
	int cnt = 1;
	
	// ta duyet tung phan tu tu 0 -> n-1
    // Do phuc tap O(NlogN)
	
	for(int i = 0; i < n; i++){
		
		// ta khai bao bien lieu co su dung them mau moi de to cho mang
		
		int check = 0;
		
		// vi mang mau co xu huong giam dan khi them cac phan tu vao mang nen ta tim kiem nhi phan de toi uu bai toan
		
		int l = 0, r = cnt-1;
		while(l <= r){
			int m = l + (r-l)/2;
			
			// vi ta muon to mau cac phan tu co thu tu tang dan nen ta se luu cac gia tri trong mang mau la
			// cac gia tri lon nhat
			
			if (mau[m] < a[i]){
				check = 1; 
				mau[m] = a[i];
				r = m-1;
			}else{
				l = m + 1;
			}
		}
		
		// khi ta thay phan tu dang xet khong vao duoc to hop mau nao thi ta them mot mau moi
		
		if (!check){
			cnt++;
			mau[cnt-1] = a[i];
		}
	}
	
	cout << cnt; 
}
	
int main(){
	solve();
	return 0; 
}
