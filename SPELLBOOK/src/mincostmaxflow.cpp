#include <cstring>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int,int> ii;
// the maximum number of vertices + 1
#define MAXN 1024
/* FILL ME */
int cap[MAXN][MAXN];
double cost[MAXN][MAXN]; // cost per unit of flow matrix
int n, s, t, p, q, k;
ii P[500], Q[500];

// flow network and adjacency list
int x[MAXN][MAXN], adj[MAXN][MAXN], nadj[MAXN];
// Dijkstra’s successor and depth
int par[MAXN], d[MAXN]; // par[source] = source;
// Labelling function

int pi[MAXN];
#define INF (0x3f3f3f3f)

// Dijkstra’s using non-negative edge weights (cost+potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t ) {
for( int i = 0; i < n; i++ ) d[i] = INF, par[i] = -1;
d[s] = 0;
par[s] = -n - 1;

for (;;) {
// find u with smallest d[u]
int u = -1, bestD = INF;
for(int i = 0; i < n; i++) if (par[i] < 0 && d[i] < bestD)
bestD = d[u = i];
if(bestD == INF) break;

// relax edge (u,i) or (i,u) for all i;
par[u] = -par[u] - 1;
for (int i = 0; i < nadj[u]; i++)
{
// try undoing edge v->u
int v = adj[u][i];
if (par[v] >= 0 ) continue;
if (x[v][u] && d[v] > Pot(u,v) - cost[v][u])
d[v] = Pot( u, v ) - cost[v][u], par[v] = -u-1;

// try edge u->v
if (x[u][v]<cap[u][v] && d[v]>Pot(u,v)+cost[u][v])
d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
}
}

for (int i = 0; i < n; i++ ) if (pi[i] < INF) pi[i] += d[i];
return par[t] >= 0;
}
#undef Pot

int mfmc(double &fcost) {
// build the adjacency list
memset(nadj, 0, sizeof(nadj));
for(int i = 0; i < n; i++)
for(int j = 0; j < n; j++)
if(cap[i][j] || cap[j][i]) adj[i][nadj[i]++] = j;

memset(x, 0, sizeof(x));
memset(pi, 0, sizeof(pi));
int flow = 0;
fcost = 0.0;

// repeatedly, find a cheapest path from s to t
while(dijkstra(n, s, t)) {
// get the bottleneck capacity
int bot = INT_MAX;
for(int v = t, u = par[v]; v != s; u = par[v = u])
bot = min(bot, x[v][u] ? x[v][u] : (cap[u][v]-x[u][v]));
// update the flow network
for(int v = t, u = par[v]; v != s; u = par[v = u] )

if(x[v][u]) { x[v][u] -= bot; fcost -= bot*cost[v][u]; }
else { x[u][v] += bot; fcost += bot * cost[u][v]; }
flow += bot;
}
return flow;
}

double euclid(int a, int b){
	hypot(P[a].first - Q[b].first, P[a].second - Q[b].second);	
}

int main() {
cin >> p >> q >> k;
for(int i = 0; i<p; i++) cin >> P[i].first >> P[i].second;
for(int i = 0; i<q; i++) cin >> Q[i].first >> Q[i].second;

n = p+q+3;

memset( cap, 0, sizeof( cap ) );
int m, a, b, c, cp;
s = p+q;
t = p+q+2;

cap[p+q+1][p+q+2] = k;
cost[p+q+1][p+q+2] = 0.0;
// fill up cap with existing capacities.
// if the edge u->v has capacity 6, set cap[u][v] = 6.
// for each cap[u][v] > 0, set cost[u][v] to the
// cost per unit of flow along the edge u->v
for (int j=0; j<q; j++){
	cap[q+j][p+q+1] = 1;
	cost[q+j][p+q+1] = 0.0;
}

for (int i=0; i<p; i++){
	cap[p+q][i] = 1;
	cost[p+q][i] = 0.0;
	for (int j=0; j<q; j++){
		cap[i][q+j] = 1;
		cost[i][q+j] = euclid(i, j);
	}
}

double fcost;
int flow = mfmc(fcost);
cout << fcost << endl;
return 0;
}
