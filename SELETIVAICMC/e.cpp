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
#include <deque>
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

#define MAX_V 1100


int t, n, m , k;
int grau[MAX_V];
ii G[MAX_V][MAX_V];
int mAdj[MAX_V][MAX_V];
int dist[MAX_V][MAX_V];

priority_queue< ii, vector< pair<int, ii> >, greater< pair<int, ii> > > pq;
	
int dijkstra(int s, int t){
	CLEAR(dist, INF);
	pq = priority_queue< ii, vector< pair<int, ii > >, greater< pair<int, ii> > >();
	pq.push(pair< int, ii >(0, ii(-1, s)));
	dist[1][s] = 0;
	while(!pq.empty()){
		pair< int, ii > f = pq.top(); pq.pop();
		int d = f.first, u = f.second.second, p = -f.second.first;
		if(d > dist[p][u]) continue;
		REP(j, grau[u]){
			ii v = G[u][j];
			if(p+1 <= k && dist[p][u] + v.second < dist[p+1][v.first]){
				dist[p+1][v.first] = dist[p][u] + v.second;
				if(v.first == t) return dist[p+1][v.first];
				pq.push(pair<int, ii >(dist[p+1][v.first], ii(-(p+1), v.first)));
			}
		}
	}
	
	return INF;
}

int main(){
	cin >> t;
    while(t--){
		cin >> n >> m >> k;
		CLEAR(mAdj, INF);
		int u, v, w;
		REP(i, m){
			scanf(" %d %d %d ", &u, &v, &w);
			mAdj[u][v] = min(mAdj[u][v], w);
		}
		CLEAR0(grau);
		REP(i, n)
		REP(j, n){
			if(mAdj[i][j] != INF) G[i][grau[i]++] = ii(j, mAdj[i][j]);
		}
		
		int ans = dijkstra(0, n-1);
		if(ans == INF) cout << "-1\n";
		else cout << ans << endl;
	}
}

