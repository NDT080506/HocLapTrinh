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

void dao(char s[]){
	char tmp[100001];
	int n = strlen(s);
	
	for(int i = 0; i < n; i++){
		tmp[i] = s[n-i-1];
	}
	
	tmp[n] = '\0';
	strcpy(s, tmp);
}

char ans[101];

int main() {
	
	char s[101];
	scanf("%s", s);
	
	dao(s);
	while(strlen(s) % 3 != 0) strcat(s, "0");	
	dao(s);
	
	int n = strlen(s);
	
	int k = 0;
	for(int i = n-1; i >= 0; i-=3){
		char tmp[4];
		int len = 0;
		for(int j = i; j > i-3; j--){
			tmp[len++] = s[j]; 
		}
		tmp[len] = '\0';
		//printf("%s\n", tmp);
		int decade = 0;
		for(int t = len-1; t >= 0; t--){
			if (tmp[t] == '1') decade += pow(2,t);
		}
		
		//printf("%d\n", decade);
		ans[k++] = (decade + '0');
	}
	
	ans[k] = '\0';
	dao(ans);
	puts(ans);
	
	return 0;
}
