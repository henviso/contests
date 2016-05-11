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
int numSCC;
int V;
bool mat[MAXV][MAXV];
vi g[6*MAXV], f[6*MAXV];
int pos[6*MAXV], component[6*MAXV], idx;
bool val[6*MAXV];
stack<int> st;
bitset<6*MAXV> vis;

void dfs(int v){
	vis[v] = true;
	REP(i, g[v].size()) if(!vis[g[v][i]]) dfs(g[v][i]);
	st.push(v);
}

void dfs2(int v){
	vis[v] = true;
	REP(i, f[v].size()) if(!vis[f[v][i]]) dfs2(f[v][i]);
	component[v] = numSCC;
	pos[v] = idx++;
}

bool Kosaraju(){
	numSCC = 0;
	vis.reset();
	REP(i, V) if(!vis[i]) dfs(i);
	vis.reset();
	idx = 0;
	while(!st.empty()){
		int v = st.top(); st.pop();
		if(!vis[v]){
			numSCC++;
			dfs2(v);
		}
	}
	REP(i, V) if(component[i] == component[i^1]) return false;
	REP(i, V) if(pos[i] < pos[i^1]) val[i] = true;
	else val[i] = false;
	return true;
}

int main(){
	while(scanf(" %d %d ", &n, &m) != EOF){
		int v, w, x, y;
		V = n*6;
		CLEAR0(mat);
		REP(i, V){ g[i].clear(); f[i].clear(); }
		REP(i, n){
			REP(j, 3)
			REP(k, 3){
				if(j == k) continue;
				x = 2*(i + n*j);
				y = (2*(i + n*k))^1;
				g[x].push_back(y);
				f[y].push_back(x);		
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
						f[y].push_back(x);
						//x = 2*(z + n*k);
						//y = (2*(i + n*k))^1;
						//g[x].push_back(y);
						//f[y].push_back(x);
					}
				}
			}
		}
		if(Kosaraju()){
			REP(i, 2){
				REP(j, 2){
					int x = i + j*2*n;
					if(val[x]){
						printf("%d", i+1);
						REP(k, n){
							if(k == i) continue;
							if(val[k + j*2*n]) printf(" %d", k+1);
						}
					}
				}
				printf("\n");
			}
		}
		else printf("Impossible\n");
		
		REP(i, V){
			printf("%d: ", i);
			REP(j, g[i].size()) printf("%d ", g[i][j]);
			printf("\n");
		}
		REP(i, V) cout << "I " << i << " COMP " << component[i] << " POS " << pos[i] <<  " VAL " << i << " : " << val[i] << endl;
		
	}
}
