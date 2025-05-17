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
	char ma[101];
	char ten[55];
	char donvi[25];
	char thoidiem[10];
	char gio[10];
	char phut[10];
	int vantoc;
} taydua;

void sapxep(taydua td[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (strcmp(td[i].gio, td[j].gio) < 0){
				taydua tmp = td[i]; td[i] = td[j]; td[j] = tmp; 
			}else if (strcmp(td[i].gio, td[j].gio) == 0 && strcmp(td[i].phut, td[j].phut) < 0){
				taydua tmp = td[i]; td[i] = td[j]; td[j] = tmp; 
			}
		}
	}
}


int main() {
	
	int n;
	scanf("%d", &n);
	
	taydua td[n];
	
	fo(i,n){
		scanf(" %[^\n]s", td[i].ten);
		scanf(" %[^\n]s", td[i].donvi);
		scanf(" %[^\n]s", td[i].thoidiem);
	}
		
	fo(i,n){
		
		char *p = strtok(td[i].thoidiem, ":");
		int t = 0;
		while(p != NULL){
			if (t==0) strcpy(td[i].gio, p);
			else if (t==1) strcpy(td[i].phut, p);
			t++;
			p = strtok(NULL, ":");
		}
	}
	
	fo(i,n){
		int x = atoi(td[i].gio);
		int y = atoi(td[i].phut);
		
		double a = (double)x;
		double b = (double)y;
		
		b = (double)b / 60;
		
		//printf("%.1lf %.1lf\n", a, b);
		double v = round((double)(120 / (a+b-6)));
		
		int ans = v;
		td[i].vantoc = ans;
	}
	
	sapxep(td, n);
	
	
	fo(i,n){
		
		char tmp1[55], tmp2[55];
		strcpy(tmp1, td[i].donvi);
		strcpy(tmp2, td[i].ten);
		char *p = strtok(tmp1, " ");
		while(p != NULL){
			printf("%c", p[0]);
			p = strtok(NULL, " ");
		}
		
		char *t = strtok(tmp2, " ");
		while(t != NULL){
			printf("%c", t[0]);
			t = strtok(NULL, " ");
		}
		
		printf(" ");
		printf("%s ", td[i].ten);
		printf("%s ", td[i].donvi);
		printf("%d Km/h", td[i].vantoc);
		printf("\n");
	}
	
		
	return 0;
}
