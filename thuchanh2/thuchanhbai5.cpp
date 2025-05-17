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

char p[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

void dao(char s[]){
	char tmp[1001];
	int n = strlen(s);
	
	for(int i = 0; i < n; i++){
		tmp[i] = s[n-i-1];
	}
	
	tmp[n] = '\0';
	strcpy(s, tmp);
}

int main() {
	
	int n;
	while(1){
		scanf("%d", &n);
		if (n == 0) break;
		char s[101];
		scanf("%s", s);
		
		int len = strlen(s);
		for(int i = 0; i < len; i++){
			for(int j = 0; j < 28; j++){
				if (p[j] == s[i]){
					s[i] = p[(j+n)%28];
					break;
				}
			}
		} 
		
		dao(s);
		puts(s);
		printf("\n");
		
	}
	
	return 0;
}
