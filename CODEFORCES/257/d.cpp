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
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-11
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//scanf(" %d ", &t);

#define MAX_V 100010

class EDGES{
	public:
	int u, v, w;
};

int n, m, k;
vii G[MAX_V];
EDGES a[500000];
vi dist;
ii d[MAX_V];
vii H[MAX_V];

int dijkstra(int s, int t){
	dist.assign(MAX_V, INF); dist[s] = 0;
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

int main(){
	cin >> n >> m >> k;
	REP(i, m){
		cin >> a[i].u >> a[i].v >> a[i].w;
		G[a[i].u].push_back(ii(a[i].v, a[i].w));
		G[a[i].v].push_back(ii(a[i].u, a[i].w));
	}
	REPP(i, m, m+k){
		a[i].u = 1;
		cin >> a[i].v >> a[i].w;
		G[1].push_back(ii(a[i].v, a[i].w));
		G[a[i].v].push_back(ii(1, a[i].w));
	}
	bitset<500000> vis; vis.reset();
	int ans = 0;
	dijkstra(1, n);
	REP(i, m+k){
		int u = a[i].u, v = a[i].v, w = a[i].w;
		bool used = false;
		if(dist[u] + w == dist[v]){
			H[v].push_back(ii(u, w));
			if(i >= m) vis[i] = true;
		}
		swap(u, v);
		if(dist[u] + w == dist[v]){
			H[v].push_back(ii(u, w));
			if(i >= m) vis[i] = true;
		}
		if(!vis[i]) ans++;
	}
	REPP(i, m, m+k){
		int u = a[i].u, v = a[i].v, w = a[i].w;
		if(vis[i] && G[v].size() > 1){
			REP(j, G[v].size()){
				if(G[v][j].first == u){
					G[v].erase(G[v].begin()+j);
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}

