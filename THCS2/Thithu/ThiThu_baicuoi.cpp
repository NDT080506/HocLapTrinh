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


typedef struct{
	int ma;
	char ngaythi[101];
	char ngay[3];
	char thang[3];
	char nam[5];
	char giothi[101];
	char gio[3];
	char phut[3];
	char phongthi[101];
} cathi;


void sapxep(cathi ct[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n; j++){
			if (strcmp(ct[i].nam, ct[j].nam) > 0){
				cathi tmp = ct[i]; ct[i] = ct[j]; ct[j] = tmp;
			}else if (strcmp(ct[i].nam, ct[j].nam) == 0 && strcmp(ct[i].thang, ct[j].thang) > 0){
				cathi tmp = ct[i]; ct[i] = ct[j]; ct[j] = tmp;
			}else if (strcmp(ct[i].nam, ct[j].nam) == 0 && strcmp(ct[i].thang, ct[j].thang) == 0 && strcmp(ct[i].ngay, ct[j].ngay) > 0){
				cathi tmp = ct[i]; ct[i] = ct[j]; ct[j] = tmp;
			}else if (strcmp(ct[i].nam, ct[j].nam) == 0 && strcmp(ct[i].thang, ct[j].thang) == 0 && strcmp(ct[i].ngay, ct[j].ngay) == 0 && strcmp(ct[i].gio, ct[j].gio) > 0){
				cathi tmp = ct[i]; ct[i] = ct[j]; ct[j] = tmp;
			}else if (strcmp(ct[i].nam, ct[j].nam) == 0 && strcmp(ct[i].thang, ct[j].thang) == 0 && strcmp(ct[i].ngay, ct[j].ngay) == 0 && strcmp(ct[i].gio, ct[j].gio) == 0 && strcmp(ct[i].phut, ct[j].phut) > 0){
				cathi tmp = ct[i]; ct[i] = ct[j]; ct[j] = tmp;
			}else if (strcmp(ct[i].nam, ct[j].nam) == 0 && strcmp(ct[i].thang, ct[j].thang) == 0 && strcmp(ct[i].ngay, ct[j].ngay) == 0 && strcmp(ct[i].gio, ct[j].gio) == 0 && strcmp(ct[i].phut, ct[j].phut) == 0 && ct[i].ma > ct[j].ma){
				cathi tmp = ct[i]; ct[i] = ct[j]; ct[j] = tmp;
			}
		}
	}
}

int soluong = 1;
int main() {
	int n;
	scanf("%d", &n);
	
	cathi ct[n];
	fo(i,n){
		ct[i].ma = soluong;
		soluong++;
		scanf(" %[^\n]", ct[i].ngaythi);
		scanf(" %[^\n]", ct[i].giothi);
		scanf(" %[^\n]", ct[i].phongthi);
	}
	
	fo(i,n){
		
		char s[101];
		strcpy(s, ct[i].ngaythi);
		
		char *p = strtok(s, "/");
		int len = 0;
		while(p != NULL){
			if (len==0)strcpy(ct[i].ngay, p);
			else if (len==1) strcpy(ct[i].thang, p);
			else if (len==2) strcpy(ct[i].nam, p);
			len++;
			p = strtok(NULL, "/");
		}
		
		char s1[101];
		strcpy(s1, ct[i].giothi);
		char *t = strtok(s1, ":");
		int m = 0;
		while(t != NULL){
			if (m==0)strcpy(ct[i].gio, t);
			else if (m==1) strcpy(ct[i].phut, t);
			m++;
			t = strtok(NULL, ":");
		}
	}
	
	
	sapxep(ct, n);
	
	fo(i,n){
		if (ct[i].ma < 10) printf("C00%d ", ct[i].ma);
		else if (ct[i].ma >= 10 && ct[i].ma < 100) printf("C0%d ", ct[i].ma);
		else if (ct[i].ma >= 100) printf("C%d ", ct[i].ma);
		
		printf("%s %s %s", ct[i].ngaythi, ct[i].giothi, ct[i].phongthi);
		printf("\n");
	}
	return 0;
}


