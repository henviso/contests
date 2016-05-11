#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>

#define ALL(x) (x).begin(),x.end()
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define INF 0x3f3f3f3f

using namespace std;

class EllysLamps {
	public:
	
	int g[110][110];
	int grau[110];
	int n, N;
	int mate[110][110];
	bitset<110> vis;
	
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
    CLEAR(mate, -INF);
    int mcbm = 0;
    REPP(i, 1, n+1){
        vis.reset();
        ans += aug(i);
    }
    return mcbm;
}
	
	int getMin(string lamps) {
		int n = lamps.length();
		vis.reset();
		
		vector<int> p, q;
		REP(i, n){
			if(lamps[i] == 'N') p.push_back(i);
			else q.push_back(i);
		}
		
		CLEAR0(grau);
		REP(i, p.size()){
			REP(j, q.size()){
				if(q[j] == p[i]+1 || q[j] == p[i]-1){
					int u = p[i], v = q[j];
					g[u][grau[u]++] = v;
					g[v][grau[v]++] = u;
				}
			}
		}
		
		int mcbm = MCBM();
		
		int ans = q.size();
		ans -= mcbm; 
		return ans;
		
	}
};
