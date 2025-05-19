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





int main() {
	
	int n;
	scanf("%d", &n);
	
	int a[n][n];
	fo(i,n){
		fo(j,n){
			scanf("%d", &a[i][j]);
		}
	}
	
	int b[n*n+1];
	int len = 0;
	fo(i,n){
		fo(j,n){
			b[len++] = a[i][j];
		}
	}
	
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			if (b[i] <= b[j]){
				int tmp = b[i]; b[i] = b[j]; b[j] = tmp;
			}
		}
	}
	
	
	int c[101][101];
	
	int k = 0;
	int d = 0;
	
	while(k <= n/2){
		for(int i = k; i < n-k; i++) c[k][i] = b[d++];
		for(int i = k+1; i < n-k; i++) c[i][n-k-1] = b[d++];
		for(int i = n-k-2; i >= k; i--) c[n-k-1][i] = b[d++];
		for(int i = n-k-2; i > k; i--) c[i][k] = b[d++];
		k++;
	}
	
	fo(i,n){
		fo(j, n){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}


