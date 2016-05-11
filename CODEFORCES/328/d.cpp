#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
#include <iomanip>
#include <utility>    
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
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-10
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);
//L[i]=L[i/2]+1;

int n, m;
vi g[200000];
bitset<200000> marked;
bitset<200000> vis;
vi lastLayer;

int bfs(int s){
	lastLayer.clear();
	queue<int> q; q.push(s); q.push(-1);
	int p = 0;
	int v; vis.reset();
	while(q.size() != 1 || q.front() != -1){
		v = q.front(); q.pop();
		if(v == -1){ lastLayer.clear(); q.push(-1); p++; v = q.front(); q.pop(); }
		vis[v] = true;
		lastLayer.push_back(v);
		REP(i, g[v].size()){
			int w = g[v][i];
			if(!vis[w]){
				q.push(w);
			}
		}
	}
	return p;
}



int main(){
	cin >> n >> m;
	int u, v;
	REP(i, n-1){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	marked.reset();
	int x;
	REP(i, m){
		cin >> x;
		marked[x] = true;
	}
	REPP(i, 1, n+1){
		int x = i;
		while(!marked[x] && g[x].size() == 1){
			int y = g[x][0];
			g[x].clear();
			REP(j, g[y].size()){
				if(g[y][j] == x){
					g[y].erase(g[y].begin()+j);
					break;
				}
			}
			x = y;
		}
	}
	int ans = n, ans2 = 0, ed = 0;
	REPP(i, 1, n+1){
		ed += g[i].size();
		if(marked[i]){
			v = i;
		}		
	}
	bfs(v); sort(lastLayer.begin(), lastLayer.end());
	v = lastLayer[0];
	int path = bfs(lastLayer[0]);
	lastLayer.push_back(v);
	sort(lastLayer.begin(), lastLayer.end());
	ans = lastLayer[0];
	ans2 = ed-path;
	cout << ans << endl;
	cout << ans2 << endl;
	
}
