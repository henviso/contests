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

vi pset, psize, ft;
vi g[30100];
int n, q;
int P[30100];
int fp[30100];
bitset<30100> vis;

int Q[300100][3];
int chainNo=0,chainHead[30100],chainPos[30100],chainInd[30100],chainSize[30100],chainAc[30100];
int subsize[30100];
int p[30100], l[30100];
int ac[30100][15];

void initSet(int N){
	pset.assign(N, 0);
	psize.assign(N, 0);
	REP(i, N){ pset[i] = i; psize[i] = 1; }
}

int findSet(int x){
	if(x == pset[x]) return x;
	return (pset[x] = findSet(pset[x]));
}

bool inSameSet(int x, int y){
	return (findSet(x) == findSet(y));
}

void unionSet(int x, int y){
	if(psize[findSet(x)] < psize[findSet(y)]) swap(x, y);
	psize[findSet(x)] += psize[findSet(y)];
	psize[findSet(y)] = 0;
	pset[findSet(y)] = findSet(x);
}


void ft_create(vi &t, int n){ t.assign(n+1, 0); }

int ft_rsq(const vi &t, int b){
	int sum = 0; for(; b; b -= CHECKFIRST(b)) sum += t[b];
	return sum;
}

int ft_rsq(const vi &t, int a, int b){
	if(a > b) swap(a, b);
	return ft_rsq(t, b) - (a == 1? 0 : ft_rsq(t, a-1)); 
}

void ft_adjust(vi &t, int k, int v){
	for(; k  <= (int)t.size(); k += CHECKFIRST(k)) t[k] += v;
}

void hld(int cur) {
	//cout << " CHAMANDO HLD " << cur << endl;
    if(chainHead[chainNo] == -1){
		chainHead[chainNo] = cur;
		chainAc[chainNo] = (chainNo == 0)? 0 : chainAc[chainNo-1] + chainSize[chainNo-1];
		//cout << "CORRENTE " << chainNo << " AC " << chainAc[chainNo] << endl;
	}
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
    //cout << " POSICAO " << chainAc[chainNo] + chainPos[cur]+1 << " DA FT CORRESPONDE AO VERT " << cur << " TEM VALOR " << P[cur] << endl;
    ft_adjust(ft, chainAc[chainNo] + chainPos[cur]+1, P[cur]);
    chainSize[chainNo]++;
 
    int ind = -1, mai = -1;
    for(int i = 0; i < g[cur].size(); i++) {         
		if(g[cur][i] != p[cur] && subsize[g[cur][i]] > mai) {
            mai = subsize[ g[cur][i] ];
            ind = i;
        }
    }
 
    if(ind >= 0) hld( g[cur][ind] );
 
    for(int i = 0; i < g[cur].size(); i++) {
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

void precalc(){
	vis.reset();
	REPP(i, 1, n+1){
		chainInd[i] = chainHead[i] = -1;
		if(!vis[i]) dfs(i, -1, 0);
	}
	CLEAR0(chainSize);
	prelca();
	REPP(i, 1, n+1) if(chainInd[i] == -1) hld(i);
	initSet(n+10);
}

int chainIndex(int x){
	return chainAc[chainInd[x]] + chainPos[x]+1;
}

int queryUp(int u, int v){
	int ans = 0;
	while(chainInd[u] != chainInd[v]){
		ans += ft_rsq(ft, chainIndex(chainHead[chainInd[u]]),  chainIndex(u));
		u = p[chainHead[chainInd[u]]];
	}
	ans += ft_rsq(ft, chainIndex(u), chainIndex(v)); 
	return ans;
}

int query(int u, int v){
	int lc = lca(u, v);
	return (queryUp(u, lc) + queryUp(v, lc) - P[lc]);
}

int main(){
	while(scanf(" %d ", &n) != EOF){
		ft_create(ft, n+10);
		initSet(n+10);
		REPP(i, 1, n+1) g[i].clear();
		REPP(i, 1, n+1) scanf(" %d ", &P[i]);
		scanf(" %d ", &q);
		char s[100];
		REP(i, q){
			scanf(" %s %d %d ", &s[0], &Q[i][1], &Q[i][2]);
			if(s[0] == 'b'){
				Q[i][0] = 1;
				if(!inSameSet(Q[i][1], Q[i][2])){
					g[Q[i][1]].push_back(Q[i][2]);
					g[Q[i][2]].push_back(Q[i][1]);
					unionSet(Q[i][1], Q[i][2]);
				}
			}
			else if(s[0] == 'p') Q[i][0] = 2;
			else Q[i][0] = 3;
		}
		precalc();
		REP(i, q){
			if(Q[i][0] == 1){
				if(!inSameSet(Q[i][1], Q[i][2])){
					printf("yes\n");
					unionSet(Q[i][1], Q[i][2]);
				}
				else printf("no\n");
			}
			else if(Q[i][0] == 2){
				int k = Q[i][2]-P[Q[i][1]];
				P[Q[i][1]] = Q[i][2];
				ft_adjust(ft, chainIndex(Q[i][1]), k);
			}
			else{
				if(!inSameSet(Q[i][1], Q[i][2])) printf("impossible\n");
				else printf("%d\n", query(Q[i][1], Q[i][2]));				
			}
		}
		
	}
	
}
