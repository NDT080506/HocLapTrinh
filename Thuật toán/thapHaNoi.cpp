#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define fo(i,n) for(int i = 0; i < (n); i++)
#define min(a,b) ((a < b)? a : b)
#define max(a,b) ((a > b)? a : b)
#define MAX_N 1000000
typedef long long ll;

void thaphanoi(char from, char to, char temp, int n){
	if (n == 1){
		printf("%c -> %c\n", from, to);
		return;	
	}
	
	thaphanoi(from, temp, to, n-1);
	printf("%c -> %c\n", from, to);
	thaphanoi(temp, to, from, n-1);
	
}

int main() {
	
	thaphanoi('A', 'C', 'B', 3);
	
	return 0;
}






