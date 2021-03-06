#include <iostream>
#include <cstdio>
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
#include <cstring>
#include <unistd.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
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
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define MOD 1000003LL
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
#define EPS 10e-20
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, t;
int row[50];
int tot;
int won;

int p1won(){
	int v[n+1], ans = 0, mx = 0;
	CLEAR0(v);
	REPP(i, 1, n+1) mx = max(mx, ++v[row[i]]);
	return (v[1] == mx);
}

void bt(int col){
	if(col == n+1){
		tot++;
		if(p1won()) won++;
		return;
	}
	REPP(i, 1, n+1){
		if(row[col-1] == i) continue;
		row[col] = i;
		bt(col+1);
	}
}

int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d ", &n);
		row[0] = -1;
		won = tot = 0;
		bt(1);
		double p = ((double) won)/((double) tot);
		double ans = n*p;
		//REP(i, n+1) tot += ev[i];
		//REP(i, n+1) ans += i*(((double) ev[i])/tot);
		cout << "WON " << won << " TOTAL " << to 
		printf("%lf\n", ans);
	}
}
