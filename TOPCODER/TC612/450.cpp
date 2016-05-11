#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 400
#define INF 0x3f3f3f3f

#define ALL(x) (x).begin(),x.end()
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)

using namespace std;

class SpecialCells {
	public:
	int n, m;
	vector <int> X, Y;
	
	int cap[MAXN][MAXN], s, t, p, q;
	int adj[MAXN][MAXN], nadj[MAXN];
	int x[MAXN][MAXN], r[MAXN][MAXN];
	int vis[MAXN], pred[MAXN], delta[MAXN];
	int aumenta() {
	int u;
		queue<int> Q;
		memset(vis, 0, sizeof(vis));
		vis[s] = 1; pred[s] = -1; delta[s] = INF;
		Q.push(s);
		while (!Q.empty()) {
			u = Q.front(); Q.pop();
			if (u == t) break;
			for (int i = 0; i < nadj[u]; i++) {
			int v = adj[u][i];
			if (!vis[v] && r[u][v] > 0) {
			vis[v] = 1; pred[v] = u;
			delta[v] = min(delta[u], r[u][v]);
			Q.push(v);
			}
			}
		}
		if (u != t) return 0;
		while (pred[u] != -1) {
			x[pred[u]][u] += delta[t]; r[pred[u]][u] -= delta[t];
			x[u][pred[u]] -= delta[t]; r[u][pred[u]] += delta[t];
			u = pred[u];
		}
		return delta[t];
	}

	int maxflow() {
		int inc, res = 0;
		/* constroi lista de adjacencias */
		memset(nadj, 0, sizeof(nadj));
		memset(x, 0, sizeof(x));
		memcpy(r, cap, sizeof(r));
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		if (cap[i][j] || cap[j][i]) adj[i][nadj[i]++] = j;
		while ((inc = aumenta()) > 0)
		res += inc;
		return res;
	}
	
	int guess(vector <int> x, vector <int> y) {
		n = x.size();
		X = x; Y = y;
		set<pair<int, int> > valid;
		REP(i, n) valid.insert(ii(x[i], y[i]));
		REP(i, n){ 
			cap[0][i+1] = 1;
			REP(j, n){
				adj[i][j]
				if(valid.count(ii(x[i], y[j])) != 0){
					cap[i+1][j+n+1] = 0;
				}
				else cap[i+1][j+n+1] = 1;
			}
		}
		REP(j, n) cap[j+n][2*n+2] = 1;
			
		REP(i, n) s[x[i]][y[i]] = true;
		REP(i, n)
		REP(j, n){
		
		}
		
	}
};


// Powered by FileEdit
