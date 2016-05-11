#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
#include <iomanip>
#include <utility>   
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector< ii > vii;
typedef vector< ll > vll;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define INF 1000000000

int t, n;
string a, b;
int A[200000], B[200000];

int transform(string x, string y){
	if(x.length() != y.length()) return INF;
	int T = x.length();
	bool paint = false;
	char l = x[T-1];
	int i = T-1, ans = 0;
	while(i >= 0){
		if(!paint){
			if(x[i] != y[i]){
				paint = true;
				l = y[i];
				ans++;
			}
		}
		else{
			//cout << " L " << l << " Y[i] " << y[i] << endl;
			if(l != y[i]){
				l = y[i];
				ans++;
			}
		}
		i--;
	}
	return ans;
}

int main(){
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> n;
		cin >> a >> b;
		int ans = INF;
		A[0] = 1;
		REPP(i, 1, n+1){
			if(a[i] != a[i-1]){
				A[i] = A[i-1]+1;
			}
			else A[i] = A[i-1];
		}
		REP(i, n+1){
			string x = (i == 0)? "" : a.substr(0, i);
			string y = (i == n)? "" : a.substr(i, n-i);
			reverse(y.begin(), y.end());
			string z = (i == 0)? "" : b.substr(0, i);
			string w = (i == n)? "" : b.substr(i, n-i);
			reverse(w.begin(), w.end());
			//cout << "x:" << x << " y:" << y << " z:" << z << " w:" << w << endl;
			//cout << transform(x, z) << " " << transform(y, w) << endl;
			ans = min(ans, max(transform(x, z), transform(y, w)));
		}
		cout << "Case #" << tc << ": " << ans << endl; 
	}
}

