#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define fo(i, a, n) for (int i = a; i < (n); ++i)
#define fi(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define Unique(v) v.erase(unique(all(v)), v.end())
#define PI 3.141592653589793238

const ll mod = 1e9 + 7;
const int maxn = 200;
double eps = 1e-9;

int priority(string s) {
    if (s == "(") return 0;
    if (s == "+" || s == "-") return 1;
    if (s == "*" || s == "/") return 2;
    return 3;
}


void solve(){
	string s; cin >> s;
	
	vector<string> a;
	fo(i, 0, (int)s.size()){
		int j = i;
		string tmp = "";
		if (s[j] >= '0' && s[j] <= '9'){
			while(j < (int)s.size() && s[j] >= '0' && s[j] <= '9'){
				tmp += s[j];
				++j;
			}	
		}else{
			tmp += s[j];
		}
		a.push_back(tmp);
		if (j > i) i = j-1;
	}
	
	
	stack<string> st;
	vector<string> output;
	
	fo(i, 0, (int)a.size()){
		if (a[i] == "(") st.push(a[i]);
		else if (a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/"){
			while(!st.empty() && priority(st.top()) >= priority(a[i])){
		        if (st.top() == "(") break;
		        output.push_back(st.top());
		        st.pop();
		    }
    		st.push(a[i]);
		}else if (a[i] == ")"){
			while(1){
				string y = st.top(); st.pop();
				if (y == "(") break;
				output.push_back(y);
			}	
		}else{
			output.push_back(a[i]);
		}
	} 
	
	while(!st.empty()){
		string x = st.top(); st.pop();
		output.push_back(x);
	}
	
	
	stack<ll> sts;
	
	fo(i, 0, (int)output.size()){
		if (output[i] == "+" || output[i] == "-" || output[i] == "*" || output[i] == "/"){
			ll num1 = sts.top(); sts.pop();
			ll num2 = sts.top(); sts.pop();
			
			ll num = 0;
			if (output[i] == "+"){
				num = num2 + num1;		
			}else if (output[i] == "-"){
				num = num2 - num1;
			}else if (output[i] == "*"){
				num = num1 * num2;
			}else{
				num = num2 / num1;
			}
			
			sts.push(num);
		}else{
			sts.push(stoll(output[i]));
		}
	}
	
	
	cout << sts.top();
}


int main() {
//	freopen("debug_inp.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		solve();
		cout << "\n";	
	}
	
//	solve();
	return 0;
}

