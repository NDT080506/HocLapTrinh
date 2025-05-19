#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define fo(i,n) for(int i = 0; i < (n); i++)
#define min(a,b) ((a < b)? a : b)
#define max(a,b) ((a > b)? a : b)
#define MAX_N 100000
typedef long long ll;


typedef struct{
	char ma[11];
	char ten[105];
	ll soluong;
	ll dongia;
	ll chietkhau;
	ll tong;
} hanghoa;

void sapxep(hanghoa hh[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (hh[i].tong > hh[j].tong){
				hanghoa tmp = hh[i]; hh[i] = hh[j]; hh[j] = tmp;
			}
		}
	}
}


int main() {
	
	int n;
	scanf("%d", &n);
	
	hanghoa hh[n];
	fo(i,n){
		scanf("%s", hh[i].ma);
		scanf(" %[^\n]", hh[i].ten);
		scanf("%lld", &hh[i].soluong);
		scanf("%lld", &hh[i].dongia);
		scanf("%lld", &hh[i].chietkhau);
	}
	
	fo(i,n){
		hh[i].tong = (hh[i].dongia * hh[i].soluong) - hh[i].chietkhau;
	}
	
	sapxep(hh, n);
	
	fo(i,n){
		printf("%s %s %lld %lld %lld %lld", hh[i].ma, hh[i].ten, hh[i].soluong, hh[i].dongia, hh[i].chietkhau, hh[i].tong);
		printf("\n");
	}
	
	return 0;
}
