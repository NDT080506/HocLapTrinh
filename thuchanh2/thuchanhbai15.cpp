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
	
	char s[101];
	while(scanf(" %[^\n]", s) != -1){
		int n = 0;
		char a[101][101];
		char *p = strtok(s, " ");
		while(p != NULL){
			fo(i, strlen(p)) p[i] = tolower(p[i]);
			strcpy(a[n], p);
			n++;
			p = strtok(NULL, " ");
		}
		
		a[0][0] = toupper(a[0][0]);
		for(int i = 0; i < n-2; i++){
			printf("%s ", a[i]);
		}
		
		printf("%s", a[n-2]);
		int k = strlen(a[n-1]);
		
		
		if (a[n-1][k-1] == '.' || a[n-1][k-1] == '!' || a[n-1][k-1] == '?'){
			if (k == 1){
				printf("%s", a[n-1]);
			}
			else printf(" %s", a[n-1]);
		}else printf(" %s.", a[n-1]);
		
		printf("\n");
	}
	
	return 0;
}
