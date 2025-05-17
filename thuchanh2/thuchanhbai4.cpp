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

void removeZeros(char s[]){
	char tmp[1001];
	int n = strlen(s);
	
	int k = 0;
	int check = 0;
	for(int i = 0; i < n; i++){
		if (s[i] != '0' && check == 0) check = 1;
		
		if(check){
			tmp[k++] = s[i]; 
		}
	}
	
	tmp[k] = '\0';
	strcpy(s, tmp);
}

void dao(char s[]){
	char tmp[1001];
	int n = strlen(s);
	
	for(int i = 0; i < n; i++){
		tmp[i] = s[n-i-1];
	}
	
	tmp[n] = '\0';
	strcpy(s, tmp);
}

char hieu[101];

int main() {
	
	char num1[1001], num2[1001];
	
	scanf("%s%s", num1, num2);
	
	removeZeros(num1); removeZeros(num2);
	
	int neg = 0;
	if (strlen(num1) < strlen(num2) || (strlen(num1) == strlen(num2) && strcmp(num1, num2) < 0)){
		char tmp[1001];
		strcpy(tmp, num1);
		strcpy(num1, num2);
		strcpy(num2, tmp);
		neg = 1;
	}
	
	dao(num1); dao(num2);
	while(strlen(num2) < strlen(num1)) strcat(num2, "0");
	int n = strlen(num1);
	
	int nho = 0;
	int len = 0;
	for(int i = 0; i < n; i++){
		int x = num1[i] - '0';
		int y = num2[i] - '0';
		int d = x-y-nho;
		if (d < 0){
			d += 10;
			nho = 1;
		}else nho = 0;
		
		hieu[len++] = d + '0';
	}
	
	if(neg){
		hieu[len] = '-';
		hieu[len+1] = '\0';
	}else hieu[len] = '\0';
	
	int ok = 0;
	
	dao(hieu);
	removeZeros(hieu);
	if (strcmp(hieu, "") == 0) printf("0");
	else puts(hieu);
	
	return 0;
}
