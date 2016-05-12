#define MAXV 510

int V;
vii G[MAXV];

int dijkstra(int s, int t){
	vi dist(V, INF); dist[s] = 0;
	priority_queue< ii, vii, greater<ii> > pq; pq.push(mp(0, s));
	while(!pq.empty()){
		ii f = pq.top(); pq.pop();
		int d = f.first, u = f.second;
		if(d > dist[u]) continue;
		REP(j, G[u].size()){
			ii v = G[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(mp(dist[v.first], v.first));
			}
		}
	}
	return dist[t];
}

int mate[MAXV], n;
bitset<MAXV> vis;

//BIPARTITE MATCHING 
int aug(int v){
    if(vis[v]) return false;
    vis[v] = true;
    REP(j, grau[v]){
        int w = g[v][j];
        if(mate[w] == -1 || aug(mate[w])){
            mate[w] = v;
            return 1;
        }
    }
    return 0;
}


int MCBM(){
    CLEAR(mate, -1);
    int mcbm = 0;
    REPP(i, 1, n+1){
        vis.reset();
        mcbm += aug(i);
    }
    return mcbm;
}
