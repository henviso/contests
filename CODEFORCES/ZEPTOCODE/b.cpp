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
#define EPS 1e-9
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
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, V;
int a[10000];
vector< ii > g[10000];
int submax[10000];
ll ans = 0;

int dfs(int v){
	submax[v] = 0;
	REP(i, g[v].size()) submax[v] = max(submax[v], dfs(g[v][i].first)+g[v][i].second);
	return submax[v];
}

int dfs2(int v, int lf){
	REP(i, g[v].size()){
		int cnt = (lf - g[v][i].second - submax[g[v][i].first]);
		ans += cnt;
		dfs2(g[v][i].first, lf - g[v][i].second - cnt);
	}
}

int main(){
	scanf(" %d ", &n);
	int v = 1;
	int aux = 0, lim = 2;
	V = (1 << n+1)-1;
	REPP(i, 2, (1 << n+1)){
		cin >> a[i];
		aux++;
		g[v].push_back(ii(1+aux, a[i]));
		if(aux == lim){ v++; lim += 2;}
	}
	dfs(1);
	dfs2(1, submax[1]);
	cout << ans << endl;
	
	
}
