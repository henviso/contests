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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
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
#define EPS 1e-9
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

#define MAXV 2100

int n, m;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;
int V;
bool mat[MAXV][MAXV];
vi g[6*MAXV];

#define UNVISITED 0

void tarjanDFS(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	REP(j, g[u].size()){
		int v = g[u][j];
		if(dfs_num[v] == UNVISITED) tarjanDFS(v);
		if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		if(dfs_low[u] == dfs_num[u]){
			printf("SCC %d:", ++numSCC);
			while(true){
				int v = S.back(); S.pop_back(); visited[v] = 0;
				printf(" %d", v);
				if(u == v) break; 
			}
			printf("\n");
		}
	}
}

void tarjanSCC(){
	dfs_num.assign(V, UNVISITED); dfs_low.assign(V, UNVISITED); visited.assign(V, UNVISITED);
	dfsNumberCounter = numSCC = 0;
	REP(i, n){
		if(dfs_num[i] == UNVISITED) tarjanDFS(i);
	}
}

int main(){
	while(scanf(" %d %d ", &n, &m) != EOF){
		int v, w, x, y;
		V = n*6;
		CLEAR0(mat);
		REP(i, V) g[i].clear();
		REP(i, n){
			REP(j, 3)
			REP(k, 3){
				if(j == k) continue;
				x = 2*(i + n*j);
				y = (2*(i + n*k))^1;
				g[x].push_back(y);
			}
		}
		REP(i, m){
			scanf(" %d %d ", &v, &w); 
			v--; w--;
			mat[v][w] = true;
			mat[w][v] = true;
		}
		REP(i, n){
			REP(z, n){
				if(i != z && !mat[i][z]){					
					REP(k, 3){
						x = 2*(i + n*k);
						y = (2*(z + n*k))^1;
						g[x].push_back(y);
						x = 2*(z + n*k);
						y = (2*(i + n*k))^1;
					}
				}
			}
		}
		REP(i, V){
			printf("%d: ", i);
			REP(j, g[i].size()) printf("%d ", g[i][j]);
			printf("\n");
		}
	}
}
