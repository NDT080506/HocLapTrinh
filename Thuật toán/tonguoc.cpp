#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
 
using ll = long long;
using namespace std;
 
const ll mod = 1000000007;
 
vector<int> sumDiv(1000001, 0);

// tinh toan tong uoc cua tung so (khong chua chinh n) trong khoang [1,n]; no co do phuc tap la (Nlogn)
void precompute(int n){
	for(int i = 1; i <= n/2; i++){
		for(int j = i*2; j <= n; j+=i){
			sumDiv[j] += i;
		}
	}
}

// tinh toan tong uoc cua tung so (co chua n) trong khoang [1,n]; no co do phuc tap la (Nlogn)
void precompute2(int n){
	for (int i = 1; i <= n; ++i) {
	    for (int j = i; j <= n; j += i) {
	        sum_div[j] += i; 
	    }
	}
}

int main(){
	
}
