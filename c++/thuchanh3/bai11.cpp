#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)

const int mod = (int)1e9 + 7;
const int maxn = (int)1e7;
double eps = 1e-9;

int fib[93];
void preproc(){
	fib[1] = 1;
	fi(i, 2, 92){
		fib[i] = fib[i-1] + fib[i-2];
	}
}


int cnt = 0;
int b[100];
int n, k;

void in(){
	++cnt;
	fi(i, 1, 92){
		if (cnt == fib[i]){
			cout << cnt << ": ";
			fi(i, 1, k) cout << b[i] << " ";
			cout << "\n";
			break;
		}else if (cnt < fib[i]) break;
	}
}

void ql(int pos){
	for(int i = b[pos-1] + 1; i <= n + pos - k; ++i){
		b[pos] = i;
		if (pos == k){
			in();
		}else{
			ql(pos+1);
		}
	}
}

void solve(){ 
	cin >> n >> k;
	ql(1);
}

int main() {
    //freopen("debug_inp.txt", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    preproc();
    solve();
	return 0;
}

