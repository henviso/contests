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

char o[300];
int f[300][300];
char l[] = {'U', 'D', 'L', 'R'};

bool val(int a, int b){
	REP(k, 4){
		int x = f[b+1][l[k]] - f[a][l[k]];
		int y = f[b+1][o[l[k]]] - f[a][o[l[k]]];
		if(x != y) return false;
	}
	return true;
}

int main(){
	o['U'] = 'D';
	o['D'] = 'U';
	o['L'] = 'R';
	o['R'] = 'L';
	while(cin >> n >> s){
		REP(i, 256) f[0][i] = 0;
		REP(i, n){
			REP(j, 256) f[i+1][j] = f[i][j];
			f[i+1][s[i]]++;
		}
		int ans = 0;
		REP(i, n)
		REPP(j, i+1, n) ans += val(i, j);
		cout << ans << endl;
	}
}

