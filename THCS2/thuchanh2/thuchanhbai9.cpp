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
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		char s[MAX_N+1];
		scanf("%s", s);
		
		int n = strlen(s);
		
		ll m = 0;
		ll cnt = 0;
		int check = 0;		
		for(int i = 0; i < n; i++){
			if (s[i] >= '0' && s[i] <= '9'){
				cnt = cnt * 10 + (s[i]-'0');
			}else{
				check = 1;
			}
			
			if (check){
				m = max(cnt, m);
				cnt = 0;
				check = 0;
			}
		}
		
		printf("%lld\n", m);
	}
	
	return 0;
}
