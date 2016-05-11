#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
#include <iomanip>    
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define UNVISITED -1
#define VISITED 1

int n, m;
vi g[100100], comp;
vector< ii > bridges;
int dfsNumberCounter = 0, dfsRoot = 0, rootChildren = 0;
vi dfs_num, dfs_low, dfs_parent;

void tarjanDFS(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	REP(j, g[u].size()){
		ii v = g[u][j];
		if(dfs_num[v] == UNVISITED) tarjanSCC(v);
		if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		if(dfs_low[u] == dfs_num[u]){
			//printf("SCC %d:", ++numSCC);
			while(true){
				int v = S.back(); S.pop_back(); visited[v] = 0;
				//printf(" %d", &v);
				comp.push_back(v);
				if(u == v) break; 
			}
			//printf("%d\n");
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

set< ii > hist;

int main(){
	scanf(" %d %d ", &n, &m);
	int u, v;
	int nm = 0;
	REP(i, m){
		scanf(" %d %d ", &u, &v);
		if(hist.count(ii(u, v))) continue;
		hist.insert(ii(u, v));
		g[u].push_back(v);
		nm++;
	}
	m = nm;
	bitset<100100> ans; ans.reset();
	dfsNumberCounter = 0; dfs_num.assign(n+10, UNVISITED); dfs_low.assign(n+10, 0); dfs_parent.assign(n+10, 0);
	REPP(v, 1, n+1) if(dfs_num[v] == UNVISITED){
		dfsRoot = v; rootChildren = 0; comp.clear(); tarjanDFS(v);
		if(comp.size() > 1){
				REP(j, comp.size()){
				ans[comp[j]] = true;
			}
		}
	}
	REPP(i, 1, n+1){
		if(i > 1) printf(" ");
		if(ans[i]) printf("1");
		else printf("0");
	}
	printf("\n");
}
