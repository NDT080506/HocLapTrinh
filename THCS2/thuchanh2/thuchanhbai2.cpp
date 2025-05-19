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

char alpha[37] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N','O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 

void dao(char s[]){
	char tmp[100001];
	int n = strlen(s);
	
	for(int i = 0; i < n; i++){
		tmp[i] = s[n-i-1];
	}
	
	tmp[n] = '\0';
	strcpy(s, tmp);
}

int main() {
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, b;
		scanf("%d%d", &n, &b);
		
		char ans[100001];
		int len = 0;
		while(n != 0){
			int x = n%b;
			n /= b;
			ans[len++] = alpha[x];	
		}
		
		ans[len] = '\0';
		dao(ans);
		printf("%s\n", ans);
	}
	
	return 0;
}
