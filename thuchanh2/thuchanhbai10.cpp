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
	int gio;
	int phut;
	int giay;
} dongho;


void sapxep(dongho clock[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if (clock[i].gio > clock[j].gio){
				dongho tmp = clock[i]; clock[i] = clock[j]; clock[j] = tmp; 
			}else if (clock[i].gio == clock[j].gio && clock[i].phut > clock[j].phut){
				dongho tmp = clock[i]; clock[i] = clock[j]; clock[j] = tmp;
			}else if (clock[i].gio == clock[j].gio && clock[i].phut == clock[j].phut && clock[i].giay > clock[j].giay){
				dongho tmp = clock[i]; clock[i] = clock[j]; clock[j] = tmp;
			}
		}
	}
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	dongho clock[n];
	
	fo(i,n){
		scanf("%d%d%d", &clock[i].gio, &clock[i].phut, &clock[i].giay);
	}
	
	sapxep(clock, n);
	
	fo(i,n){
		printf("%d %d %d\n", clock[i].gio, clock[i].phut, clock[i].giay);
	}
	
	return 0;
}
