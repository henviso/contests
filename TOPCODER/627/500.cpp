#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>
#include <set>

using namespace std;

#define CLEAR(v, x) memset(v, x, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)

typedef vector<int> vi;
typedef pair<int,int> ii;

#define INF 0x3f3f3f3f
#define CHECKFIRST(S) (S & (-S)) 


vi ft;
int n, k, ans, inv;
vi g[1100], VAL;
bitset<1100> vis;

void ft_create(vi &t, int n){ t.assign(n+1, 0); }

int ft_rsq(const vi &t, int b){
	int sum = 0; for(; b; b -= CHECKFIRST(b)) sum += t[b];
	return sum;
}

int ft_rsq(const vi &t, int a, int b){
	return ft_rsq(t, b) - (a == 1? 0 : ft_rsq(t, a-1)); 
}

void ft_adjust(vi &t, int k, int v){
	for(; k  <= (int)t.size(); k += CHECKFIRST(k)){
		t[k] += v;
	}
}

void eval(){
	ans = min(ans, inv);
}

void dfs(int s, int sz){
	vis[s] = true;
	int ic = ft_rsq(ft, VAL[s]+1, 1001); 
	inv += ic;
	ft_adjust(ft, VAL[s], 1);
	if(sz+1 == k){
		eval();
		ft_adjust(ft, VAL[s], -1);
		inv -= ic;
		vis[s] = false;
		return;
	}
	REP(j, g[s].size()){
		int v = g[s][j];
		if(!vis[v]) dfs(v, sz+1);
	}
	vis[s] = false;
	ft_adjust(ft, VAL[s], -1);
	inv -= ic;
}

class GraphInversions {
	public:
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
		n = A.size(); k = K; VAL = V;
		int u, v;
		REP(i, n){
			u = A[i], v = B[i];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = INF;
		vis.reset();
		REP(i, n){
			ft_create(ft, 1010);
			inv = 0;
			dfs(i, 0);
		}
		if(ans == INF) return -1;
		return ans;
	}
};


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
