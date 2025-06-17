
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;


int ans = 0;

void sumEqualToK(vector<int> a, int n, int k, int currSum, int pos){
	if (pos >= n){
		if (currSum == k) ans++;
		return;
	}
	
	sumEqualToK(a, n, k, currSum, pos+1);
	if (currSum + a[pos] <= k){
		sumEqualToK(a, n, k, currSum + a[pos], pos+1);
	}
	
}


int a[20];
int check[20] = {0};

void result(int n){
	
	for(int i = 1; i <= n; i++) cout << a[i];
	cout << "\n";
}



void hoanVi(int n, int pos){
	
	
	for(int i = 1; i <= n; i++){
		
		if (!check[i]){
			
			a[pos] = i;
			check[i] = 1;
			if (pos == n){
				result(pos);
			}else{
				hoanVi(n, pos+1);
			}
			
			check[i] = 0;
			
		}
		
	}
	
}


int main(){
	
	int n;
	cin >> n;
	
	hoanVi(n, 1);
	
	return 0;
}


//Day con co tong = K
//Hoan vi cua 1 chuoi

