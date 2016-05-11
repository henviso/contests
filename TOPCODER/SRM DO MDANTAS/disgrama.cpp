#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;

#define CLEAR(v, x) memset(v, x, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define MAX_V 2100
#define INF 0x3f3f3f3f
#define mp make_pair
#define UNVISITED 0
#define VISITED 1

int V;
vii G[MAX_V];
vi par[MAX_V];
vi cnt, dist;
vi dfs_num, dfs_low, S, visited;
bitset<2100> used; 
int ans, dfsNumberCounter;

class DrivingPlans {
	public:
	
	void tarjanSCC(int u){
		dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
		S.push_back(u);
		visited[u] = 1;
		for(int j = 0; j<G[u].size(); j++){
			ii v = G[u][j];
			if(v.second != 1) continue;
			if(dfs_num[v.first] == UNVISITED){
				tarjanSCC(v.first);
			}
			if(visited[v.first]) {dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); }
			if(dfs_low[u] == dfs_num[u]){
				while(1){
					int v = S.back(); S.pop_back(); visited[v] = 0;
					if(used[v]) ans = -1;
					if(u == v) break;
				}
			}
		}
	}
		
	
	int dijkstra(int s, int t){
		dist.assign(V, INF); 
		cnt.assign(V, 0);
		dist[s] = 0;
		cnt[s] = 1;
		
		priority_queue< ii, vii, greater<ii> > pq; pq.push(mp(0, s));
		while(!pq.empty()){
			ii f = pq.top(); pq.pop();
			int d = f.first, u = f.second;
			cout << "TIRANDO VER " << u << " DIST " << d << endl;
			if(d > dist[u]) continue;
			REP(j, G[u].size()){
				ii v = G[u][j];
				if(dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;
					
					cnt[v.first] = 1;
					
					par[v.first].clear();
					par[v.first].push_back(u);
					pq.push(mp(dist[v.first], v.first));
				}
				else if(dist[u] + v.second == dist[v.first]){
					cnt[v.first]++;
					
					par[v.first].push_back(u);
					pq.push(mp(dist[v.first], v.first));
				}
			}
		}
		return cnt[t];
	}
	
	int count(int N, vector <int> A, vector <int> B, vector <int> C) {
		V = N;
		int m = A.size(), u, v;
		REP(i, m){
			u = A[i]; v = B[i]; u--; v--;
			C[i]++;
			G[u].push_back(ii(v, C[i]));
			G[v].push_back(ii(u, C[i]));
		}
		ans = dijkstra(0, V-1);
		
		used.reset();
		queue<int> q; q.push(V-1);
		
		while(!q.empty()){
			v = q.front(); q.pop();
			REP(i, par[v].size()){
				if(!used[par[v][i]]){
					used[par[v][i]] = true;
					q.push(par[v][i]);
				}
			}
			par[v].clear();
		}
		REP(i, V) if(used[i]){
			REP(j, G[i].size()){
				ii w = G[i][j];
				if(w.second == 1){
					ans = -1;
					break;
				}
			}
		}
		
		dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
		REP(i, V){
			if(dfs_num[i] == UNVISITED) tarjanSCC(i);
		}
		
		return ans;
	}
};


// Powered by FileEdit
