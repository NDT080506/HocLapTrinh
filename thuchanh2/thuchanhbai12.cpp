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
	int ten[16];
	char ngay[3];
	char thang[3];
	char nam[5];
	char date[100];
} danhsach;

void sapxep(danhsach ds[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (strcmp(ds[i].nam, ds[j].nam) < 0){
				danhsach tmp = ds[i]; ds[i] = ds[j]; ds[j] = tmp; 
			}else if (strcmp(ds[i].nam, ds[j].nam) == 0 && strcmp(ds[i].thang, ds[j].thang) < 0){
				danhsach tmp = ds[i]; ds[i] = ds[j]; ds[j] = tmp;
			}else if (strcmp(ds[i].nam, ds[j].nam) == 0 && strcmp(ds[i].thang, ds[j].thang) == 0 && strcmp(ds[i].ngay, ds[j].ngay) < 0){
				danhsach tmp = ds[i]; ds[i] = ds[j]; ds[j] = tmp;
			}
		}
	}
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	danhsach ds[n];
	
	fo(i,n){
		scanf("%s%s", ds[i].ten, ds[i].date);
	}
	
	fo(i,n){
		char *p = strtok(ds[i].date, "/");
		int t = 1;
		while(p != NULL){
			if (t == 1) strcpy(ds[i].ngay, p);
			else if (t==2) strcpy(ds[i].thang, p);
			else if (t==3) strcpy(ds[i].nam, p);
			t++;
			p = strtok(NULL, "/");
		}
	}
	
	sapxep(ds, n);
	printf("%s\n", ds[n-1].ten);
	printf("%s\n", ds[0].ten);
	
	return 0;
}
