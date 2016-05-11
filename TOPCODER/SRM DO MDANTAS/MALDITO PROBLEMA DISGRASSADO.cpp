#define MAX_V 510

int V;
vii G[MAX_V];

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

//BIPARTITE MATCHING 
bool aug(int v){
    if(vis[v]) return false;
    vis[v] = true;
    REP(i, grau[v]){
        int w = g[v][i];
        if(mate[w] == -INF || aug(mate[w])){
            mate[w] = v;
            return true;
        }
    }
    return false;
}


int MCBM(){
    CLEAR(-INF);
    int mcbm = 0;
    REPP(i, 1, n+1){
        vis.reset();
        ans += aug(i);
    }
    return mcbm;
}
