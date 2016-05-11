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
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
#define CHECKFIRST(S) (S & (-S)) 
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n;
vi g[10100], st, a;
ii e[10100];
map< ii, int > edge;

char str[100];
int chainNo=0, chainHead[10100], chainPos[10100], chainInd[10100], chainSize[10100];
int subsize[10100];
int p[10100], l[10100];
int ac[10100][15];
int s[10100]; 

void st_build(vi &st, const vi &A, int vertex, int L, int R) {
  if (L == R){                          
    st[vertex] = L; 
  }                                   
  else {   
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    st_build(st, A, nL, L              , (L + R) / 2);
    st_build(st, A, nR, (L + R) / 2 + 1, R          );
    int lContent = st[nL]     , rContent = st[nR];
    int lValue   = A[lContent], rValue   = A[rContent];
    st[vertex] = (lValue >= rValue) ? lContent : rContent;
} }

void st_create(vi &st, const vi &A) {      
  int len = (int)(2*pow(2.0, floor((log((double)A.size())/log(2.0)) + 1)));
  st.assign(len, 0); 
  st_build(st, A, 1, 0, (int)A.size() - 1);         
}

int st_rmq(vi &st, const vi &A, int vertex, int L, int R, int i, int j) {
  if (i >  R || j <  L) return -1;   
  if (L >= i && R <= j) return st[vertex];        

  int p1 = st_rmq(st, A, 2 * vertex    , L              , (L+R) / 2, i, j);
  int p2 = st_rmq(st, A, 2 * vertex + 1, (L+R) / 2 + 1, R          , i, j);
                   
  if (p1 == -1) return p2;     
  if (p2 == -1) return p1;     
  return (A[p1] >= A[p2]) ? p1 : p2; }

int st_rmq(vi &st, const vi& A, int i, int j) {
  if(i > j) return 0; 
  return st_rmq(st, A, 1, 0, (int)A.size() - 1, i, j); }

int st_update_point(vi &st, vi &A, int node, int b, int e, int idx, int new_value) {
  int i = idx, j = idx;

  if (i > e || j < b)
    return st[node];

  if (b == i && e == j) {
    A[i] = new_value; 
    return st[node] = b; 
  }

  int p1, p2;
  p1 = st_update_point(st, A, 2 * node    , b              , (b + e) / 2, idx, new_value);
  p2 = st_update_point(st, A, 2 * node + 1, (b + e) / 2 + 1, e          , idx, new_value);

  return st[node] = (A[p1] >= A[p2]) ? p1 : p2;
}

int st_update_point(vi &st, vi &A, int idx, int new_value) {
  return st_update_point(st, A, 1, 0, (int)A.size() - 1, idx, new_value); }
  

void hld(int cur) {
    if(chainHead[chainNo] == -1) chainHead[chainNo] = cur;
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
    chainSize[chainNo]++;
 
    int ind = -1, mai = -1;
    REP(i, g[cur].size()){         
		if(g[cur][i] != p[cur] && subsize[g[cur][i]] > mai) {
            mai = subsize[ g[cur][i] ];
            ind = i;
        }
    }
 
    if(ind >= 0) hld( g[cur][ind] );
 
    REP(i, g[cur].size()){
        if(g[cur][i] != p[cur] && i != ind) {
            chainNo++;
            hld( g[cur][i] );
        }
    }
}

int dfs(int v, int P, int L){
	if(p[v]) return 0;
	p[v] = P;
	l[v] = L;
	subsize[v] = 1;
	REP(i, g[v].size()){
		subsize[v] += dfs(g[v][i], v, L+1);
	}
	return subsize[v];
}

void prelca(){
	CLEAR0(ac);
	REPP(i, 1, n+1) ac[i][0] = p[i];
	REPP(j, 1, 15) REPP(i, 1, n+1) if(ac[i][j-1]) ac[i][j] = ac[ac[i][j-1]][j-1];
}

int lca(int u, int v){
	int tmp, log, i;
   
	if(l[u] < l[v]) swap(u, v);
    
    for (log = 1; 1 << log <= l[u]; log++);
      log--;
   
    for (i = log; i >= 0; i--)
          if (l[u] - (1 << i) >= l[v])
              u = ac[u][i];
   if (u == v)
          return u;
   
   for (i = log; i >= 0; i--)
       if (ac[u][i] && ac[u][i] != ac[v][i])
           u = ac[u][i], v = ac[v][i];
   
   return p[u];
}

void precmp(){
	CLEAR0(p);
	dfs(1, -1, 0);
	prelca();
	REPP(i, 1, n+1) chainHead[i] = -1;
	CLEAR0(chainSize);
	hld(1); chainNo++;
	s[0] = 0;
	REPP(i, 1, chainNo) s[i] = s[i-1]+chainSize[i-1];
	a.assign(n, 0);
	REPP(i, 2, n+1){
		int ri = s[chainInd[i]]+chainPos[i];
		int u = i, v = p[i];
		//cout << " VERT " << u << " " << v;
		if(u > v) swap(u, v);
		a[ri] = edge[ii(u, v)];
		//cout << " peso " << a[ri] << " POSICAO NA ARVORE " << ri << " CHAININD " << chainInd[i] << endl;
		
	}
	st_create(st, a);
	//REP(i, n) cout << "i " << i << " a[i] " << a[i] << " rmq: " << a[st_rmq(st, a, 0, i)] << endl;
}

int queryUp(int u, int v){
	//cout << " QUERY UP DE " << u << " ATE " << v << endl;
	int ans = 0;
	while(chainInd[u] != chainInd[v]){
		ans = max(ans, a[st_rmq(st, a, s[chainInd[u]],  s[chainInd[u]]+chainPos[u])]);
		//cout << "VERIFICANDO QUERY DE " << s[chainInd[u]] << " ATE " << s[chainInd[u]] << " Q EH " << a[st_rmq(st, a, s[chainInd[u]],  s[chainInd[u]]+chainPos[u])] << endl;
		u = p[chainHead[chainInd[u]]];
	}
	//cout << "VERIFICANDO QUERY2 DE " << s[chainInd[v]]+chainPos[v]+1 << " ATE " << s[chainInd[u]]+chainPos[u] << " Q EH " << a[st_rmq(st, a, s[chainInd[v]]+chainPos[v]+1,  s[chainInd[u]]+chainPos[u])] << endl;
	return max(ans, a[st_rmq(st, a, s[chainInd[v]]+chainPos[v]+1,  s[chainInd[u]]+chainPos[u])]);
}

int query(int u, int v){
	int lc = lca(u, v);
	return max(queryUp(u, lc), queryUp(v, lc));
}

void update(int i, int x){
	//cout << "UPDATE " << i << " " << x << endl;
	int u = e[i].first, v = e[i].second;
	edge[e[i]] = x;
	//cout << " ARESTA " << u << " " << v << endl;
	if(p[u] != v) swap(u, v);
	//cout << " POSICAO " << s[chainInd[u]]+chainPos[u] << endl;
	st_update_point(st, a, s[chainInd[u]]+chainPos[u], x);
	//cout << " QUERY TESTE " << a[st_rmq(st, a, 0, n)] << " " << a[s[chainInd[u]]+chainPos[u]] << endl;
}

int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d ", &n);
		edge.clear();
		REPP(i, 1, n+1) g[i].clear();
		int u, v, w;
		REPP(i, 1, n){
			scanf(" %d %d %d ", &u, &v, &w);
			if(u > v) swap(u, v);
			e[i] = ii(u, v);
			edge[e[i]] = w;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		precmp();
		while(true){
			scanf(" %s ", str);
			if(str[0] == 'D') break;
			scanf(" %d %d ", &u, &v);
			if(str[0] == 'Q') printf("%d\n", query(u, v));
			else if(str[0] == 'C') update(u, v);
		}
	}
	
}
