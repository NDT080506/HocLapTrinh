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

int mark[256];

int main() {
	
	
	char s[1001];
	scanf("%s", s);
	
	
	int n = strlen(s);
	fo(i,n){
		mark[(int)s[i]] = 1;
	}
	
	int ans = 0;
	for(int i = 0; i <= 256; i++){
		if (mark[i] != 0) ans++; 
	}
	
	printf("%d", ans);
	
	return 0;
}
