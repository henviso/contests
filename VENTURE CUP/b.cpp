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

int n;
string s;

int main(){
	while(cin >> n >> s){
		int b = 0, g = 0, r = 0;
		REP(i, n){
			if(s[i] == 'B') b++;
			else if(s[i] == 'G') g++;
			else r++;
		}
		if(b > 0){
			if(g > 0){
				if(r > 0) cout << "BGR\n";
				else{
					if(b == 1 && g == 1) cout << "R\n";
					else if(b > 1 && g > 1) cout << "BGR\n";
					else if(b == 1 && g > 1) cout << "BR\n";
					else if(b > 1 && g == 1) cout << "GR\n";
				}
			}
			else{
				if(r > 0){
					if(b == 1 && r == 1) cout << "G\n";
					else if(b > 1 && r > 1) cout << "BGR\n";
					else if(b == 1 && r > 1) cout << "BG\n";
					else if(b > 1 && r == 1) cout << "GR\n";
				}
				else cout << "B\n";
			}
		}
		else{
			if(g > 0){
				if(r > 0){
					if(g == 1 && r == 1) cout << "B\n";
					else if(g > 1 && r > 1) cout << "BGR\n";
					else if(g == 1 && r > 1) cout << "BG\n";
					else if(g > 1 && r == 1) cout << "BR\n";
				}
				else cout << "G\n";
			}
			else if(r > 0) cout << "R\n";
		}
	}
}

