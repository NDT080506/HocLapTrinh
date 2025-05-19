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

int check(char c){
	if (c == 'a' || c == 'b' || c == 'c'){
		return 2;
	}else if (c == 'd' || c == 'e' || c == 'f'){
		return 3;
	}else if (c == 'g' || c == 'h' || c == 'i'){
		return 4;
	}else if (c == 'j' || c == 'k' || c == 'l'){
		return 5;
	}else if (c == 'm' || c == 'n' || c == 'o'){
		return 6;
	}else if (c == 'p' || c == 'q' || c == 'r' || c == 's'){
		return 7;
	}else if (c == 't' || c == 'u' || c == 'v'){
		return 8;
	}else if (c == 'w' || c == 'x' || c == 'y' || c == 'z'){
		return 9;
	}
}

int doixung(char s[]){
	int l = 0, r = strlen(s) - 1;
	while(l <= r){
		if (s[l++] != s[r--]){
			return 0;
		}
	}
	return 1;
}

int main() {
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		char s[1001];
		scanf("%s", s);
		
		
		char num[101];
		int len = 0;
		int n = strlen(s);
		
		fo(i,n) s[i] = tolower(s[i]);
		fo(i, n){
			int d = check(s[i]);
			num[len++] = d + '0';
		}
		
		num[len] = '\0';
		if (doixung(num)) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
