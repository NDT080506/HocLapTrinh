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
	scanf("%s", s);
	
	while(1){
		
		int ok = 0;	
		int index1, index2;
		int n = strlen(s);
		
		fo(i,n-1){
			if (s[i] == s[i+1]){
				index1 = i, index2 = i+1;
				ok = 1;
				break;
			}
		}
		
		if (!ok) break;
		
		char tmp[101] = "";
		int i = 0;
		int k = 0;
		while(i < n){
			if (i + 1 < n && i == index1 && i+1 == index2){
				i+=2;
			}else{
				tmp[k++] = s[i++]; 
			}
		}
		
		tmp[k] = '\0';
		strcpy(s, tmp);
		
	}
	
	if (strcmp(s, "") == 0) printf("Empty String");
	else printf("%s", s);
	
	return 0;
}
