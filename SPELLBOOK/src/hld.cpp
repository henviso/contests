#define MAX_NODES 30100
#define LOG2_MAX_NODES 15

int chainNo=0,chainHead[MAX_NODES],chainPos[MAX_NODES],chainInd[MAX_NODES],chainSize[MAX_NODES],chainAc[MAX_NODES];
int subsize[MAX_NODES];
int p[MAX_NODES], l[MAX_NODES];
int ac[MAX_NODES][LOG2_MAX_NODES];

void hld(int cur) {
	if(chainHead[chainNo] == -1){
		chainHead[chainNo] = cur;
		chainAc[chainNo] = (chainNo == 0)? 0 : chainAc[chainNo-1] + chainSize[chainNo-1];
	}
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
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

void precalc(){
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
