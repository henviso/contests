#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define EPS 1e-9
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

int n, S;
int d[2100][2100];
int dst[2100][2100];
vector< pair<int, ii> > EdgeList;
vector< ii > g[2100];
bitset<2100> vis;

vi pset;
vi psize;
 
void initSet(int N){
	pset.assign(N, 0);
	psize.assign(N, 1);
	for(int i = 0; i<N; i++) pset[i] = i;
}
 
int findSet(int i){
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
 
bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}
 
int unionSet(int i, int j){
	if(isSameSet(i,j)) return psize[findSet(j)];
	if(psize[findSet(j)] < psize[findSet(i)]) return unionSet(j, i);
	psize[findSet(j)] += psize[findSet(i)];
	pset[findSet(i)] = findSet(j);
	return psize[findSet(j)];
}

int dfs(int s, int l){
	vis[s] = true;
	dst[S][s] = l;
	REP(i, g[s].size()){
		int u = g[s][i].first;
		if(!vis[u]) dfs(u, l+g[s][i].second);
	}
}


bool solve(){
	sort(EdgeList.begin(), EdgeList.end());
	int mst_cost = 0; initSet(n);
	for (int i = 0; i < EdgeList.size(); i++) {
		pair<int, ii> front = EdgeList[i];
		int u = front.second.first, v = front.second.second, w = front.first;
		if (!isSameSet(u, v)){
			mst_cost += w;
			g[u].push_back(ii(v, w));
			g[v].push_back(ii(u, w));
			unionSet(u, v);
		}
	}
	CLEAR0(dst);
	REP(i, n){ S = i; vis.reset(); dfs(i, 0); }
	
	REP(i, n){
		REPP(j, i, n) if(d[i][j] != dst[i][j]) return false;
	}
	return true;
}

int main(){
	cin >> n;
	CLEAR0(d);
	int x;
	bool pos = true;
	REP(i, n)
	REP(j, n){
		scanf(" %d ", &x);
		int a = i, b = j;
		if(a > b) swap(a, b);
		
		if(a != b && x == 0) pos = false;
		if(d[a][b] == 0){
			d[a][b] = x;
			EdgeList.push_back(make_pair(x, ii(a, b)));
		}
		else if(d[a][b] != x) pos = false;
	}
	if(pos) pos = solve();
	
	if(pos) cout << "YES\n";
	else cout << "NO\n";
	
}
