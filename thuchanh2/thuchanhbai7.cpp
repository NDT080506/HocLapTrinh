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
	int test = 1;
	
	while(t--){
		int mark1[257];
		memset(mark1, 0, sizeof(mark1));
		int mark2[257];
		memset(mark2, 0, sizeof(mark2));
		
		char s1[1001], s2[1001];
		scanf("%s%s", s1, s2);
		
		int n = strlen(s1), m = strlen(s2);
		for(int i = 0; i < n; i++){
			mark1[(int)s1[i]]++;
		}
		
		for(int i = 0; i < m; i++){
			mark2[(int)s2[i]]++;
		}
		
		int ok = 1;
		for(int i = 0; i <= 256; i++){
			if (mark1[i] != mark2[i]){
				ok = 0;
				break;
			}
		}
		printf("Test %d: ", test);
		test++;
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
