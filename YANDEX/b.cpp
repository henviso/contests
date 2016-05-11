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
#define MOD 1000000007
//__builtin_popcount(m)
//scanf(" %d ", &t);
 
int n, m, lst = 0;
pair<int, ii > edges;
vector<ii> g[100100], h[100100];
bitset<100100> vis;
int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, S, visited;
int COMP[100100];

void tarjanSCC(int u, int k){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	vis[u] = 1;
	REPP(j, 0, g[u].size()){
		ii v = g[u][j];
		if(v.second > k) continue;
		if(dfs_num[v.first] == 0) tarjanSCC(v.first);
		if(vis[v.first]) dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}
	
	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int v = S.back(); S.pop_back(); vis[v] = 0;
			COMP[v] = numSCC;
		}
		numSCC++;	 
	}
}


bool can(int k){
	vis.reset();
	dfs_num.assign(V, 0); dfs_low.assign(V, 0); vis.reset();
	dfsNumberCounter = numSCC = 0;
	REPP(i, 1, n+1) if(dfs_num[i] == 0) tarjanSCC(i, edges[k].first);
	REP(i, k+1){
		pair<int, ii > x = edges[i];
		if(COMP[x.second.first] != COMP[x.second.second]){
			h[x.second.first].push_back(ii(x.second.second, x.first));
		}
	}
	
}

int main(){
	cin >> n >> m;
	REP(i, m){
		pair<int, ii > x;
		cin >> x.second.first >> x.second.second >> x.first;
		g[x.second.first].push_back(ii(x.second.second, x.first));
		edges.push_back(x);
	}
	sort(edges, edges+m);
	int hi = m, mid, lo = 0, ans = 0;
	while(hi-lo>1){
		mid = (hi+lo)/2;
		if(can(mid)){
			ans = mid;
			hi = mid;
		}
		else lo = mid;
	}
}
