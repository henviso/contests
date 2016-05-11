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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, a, b;
ll fe[2100][2100];
ll fu[2100][2100];

void solve(){
	CLEAR0(fe); CLEAR0(fu);
	REP(i, 2010) fe[i][0] = fu[0][i] = 1LL;
	REPP(i, 2, 2001)
	REPP(j, 1, i) fe[i][j] = (fe[i-1][j] + fe[i][j-1])%MOD;

	REPP(i, 1, 2001)
	REPP(j, i, 2001) fu[i][j] = (fu[i-1][j] + fu[i][j-1])%MOD;
}

int main(){
	solve();
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		scanf(" %d-%d ", &a, &b);
		cout << "Case #" << ca << ": " << fe[a][b] << " " << fu[b][b] << endl;
	}
}
