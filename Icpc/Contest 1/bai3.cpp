#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fi(i, n) for (int i = 1; i <= (n); i++)

using ll = long long;
using namespace std;
 
const int mod = 1e9 + 7;


void solve(){
	string s; cin >> s;
	
	// thiet lap hai con tro l, r o hai dau chuoi xau
	int l = 0, r = s.size() - 1;
	
	while(l <= r){
		
		// dung khi tro l chi vao gia tri 'A' va tro r chi vao gia tri 'Z' (thoa ma de bai)
		
		if (s[l] == 'A' && s[r] == 'Z') break;
		
		// tro l chua thoa man thi tang vi tri len
		
		if (s[l] != 'A') l++;
		
		// tro r chua thoa man thi giam vi tri xuong
		
		if (s[r] != 'Z') r--;
	}
	
	// do dai cua xau con bat dau bang 'A' va ket thuc 'Z'
	
	int ans = r-l + 1;
	cout << ans;
}
	
int main(){
	solve();
	return 0; 
}
