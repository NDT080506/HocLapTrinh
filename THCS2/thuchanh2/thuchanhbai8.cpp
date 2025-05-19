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

int isPrime(int n){
	for(int i = 2; i * i<= n; i++){
		if (n % i == 0) return 0;
	}
	return n > 1;
}

int main() {
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		char s[505];
		scanf("%s", s);
		
		int n = strlen(s);
		int ok = 1;
		for(int i = 0; i < n; i+=2){
			if ((s[i] - '0') % 2 == 1){
				ok = 0;
				break;
			}
		}
		
		if (!ok){
			printf("NO\n");
			continue;
		}
		
		for(int i = 1; i < n; i+=2){
			if ((s[i] - '0') % 2 == 0){
				ok = 0;
				break;
			}
		}
		
		if (!ok){
			printf("NO\n");
			continue;
		}
		
		int sum = 0;
		fo(i,n){
			sum += (s[i] - '0');
		}
		
		if (isPrime(sum)) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
