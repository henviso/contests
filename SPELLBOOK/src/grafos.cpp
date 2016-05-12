#define MAX_V 510

int V;
vii g[MAX_V];

int dijkstra(int s, int t){
	vi dist(V, INF); dist[s] = 0;
	priority_queue< ii, vii, greater<ii> > pq; pq.push(mp(0, s));
	while(!pq.empty()){
		ii f = pq.top(); pq.pop();
		int d = f.first, u = f.second;
		if(d > dist[u]) continue;
		REP(j, g[u].size()){
			ii v = g[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(mp(dist[v.first], v.first));
			}
		}
	}
	return dist[t];
}

//BIPARTITE MATCHING 
int n, m;
vi g[410];
int mAdj[410][410];
int mate[410];
bitset<410> vis;

bool aug(int v){
    if(vis[v]) return false;
    vis[v] = true;
    REP(i, g[v].size()){
        int w = g[v][i];
        if(mate[w] == -INF || aug(mate[w])){
            mate[w] = v;
            return true;
        }
    }
    return false;
}

int MCBM(){
    REP(i, 2*n+1) mate[i] = -INF; 
    int mcbm = 0;
    REPP(i, 1, n+1){
        vis.reset();
        mcbm += aug(i);
    }
    return mcbm;
}

//SCC

vi dfs_num, dfs_low, S, visited;
#define UNVISITED 0

void tarjanDFS(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	REP(j, g[u].size()){
		ii v = g[u][j];
		if(dfs_num[v.first] == UNVISITED) tarjanSCC(v.first);
		if(visited[v.first]) dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
		if(dfs_low[u] == dfs_num[u]){
			printf("SCC %d:", ++numSCC);
			while(true){
				int v = S.back(); S.pop_back(); visited[v] = 0;
				printf(" %d", &v);
				if(u == v) break; 
			}
			printf("%d\n");
		}
	}
}

void tarjanSCC(){
	dfs_num.assign(V, UNVISITED); dfs_low.assign(V, UNVISITED); visited.assign(V, UNVISITED);
	dfsNumberCounter = numSCC = 0;
	REP(i, V){
		if(dfs_num[i] == UNVISITED) tarjanDFS(i);
	}
}
