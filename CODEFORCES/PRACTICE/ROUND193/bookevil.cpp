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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//scanf(" %d ", &t);

vi g[100100];
int n, m, d;
bitset<100100> marked;
bitset<100100> vis;

int distDown[100100], distDown2[100100], distUp[100100];

void dfsDown(int v){
	vis[v] = true; distDown2[v] = -INF;
	int dist = (marked[v])? 0 : -INF;
	REP(i, g[v].size()){
		if(vis[g[v][i]]) continue;
		dfsDown(g[v][i]);
		//cout << " NO VERT " << v << " FILHO " << g[v][i] << " EH " << distDown[v]+1 << endl;
		if(distDown[g[v][i]]+1 > dist){
			distDown2[v] = dist;
			dist = distDown[g[v][i]]+1;
		}
		else if(distDown[g[v][i]]+1 > distDown2[v]){
			distDown2[v] = distDown[g[v][i]]+1;
		}
	}
	distDown[v] = dist;
	//cout << " DISTDOWN DE " << v << " EH " << dist<< endl;
}

void dfsUp(int p, int v){
	vis[v] = true;
	int dist = (marked[v])? 0 : -INF;
	if(p != -1){
		int tdist;
		if(distDown[p] == distDown[v]+1) tdist = max(distDown2[p]+1, distUp[p]+1);
		else tdist = max(distDown[p]+1, distUp[p]+1);
		dist = max(dist, tdist); 
	}
	//cout << " DISTUP DE " << v << " EH " << dist << endl;
	distUp[v] = dist;
	REP(i, g[v].size()){
		if(vis[g[v][i]]) continue;
		dfsUp(v, g[v][i]);
	}
}

int main(){
	int x, a, b;
	marked.reset();
	
	scanf(" %d %d %d ", &n, &m, &d);
	REP(i, m){
		scanf(" %d ", &x);
		marked[x] = true;
	}
	REP(i, n-1){
		scanf(" %d %d ", &a, &b);
		g[a].pb(b);
		g[b].pb(a);	
	}
	vis.reset();
	dfsDown(1);
	vis.reset();
	dfsUp(-1, 1);
	int ans = 0;
	REPP(i, 1, n+1){
		//cout << " PARA " << i << " EH " << max(distUp[i], distDown[i]) << endl;
		if(max(distUp[i], distDown[i]) <= d) ans++;
	}
	printf("%d\n", ans);
}
