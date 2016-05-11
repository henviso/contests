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

#define MAXCL 210000

int nc, nv;
bitset<2*MAXCL+10> ans, vis, vis2;
bitset<MAXCL+10> valid;
vi inv[2*MAXCL+10];
vi cl[MAXCL+10];
vector< ii > g[MAXCL+10];
vector< int > cycle;
int cmp = 0;

bool dfs(int v, int ed){
	if(valid[v]){
		cmp++;
		vis[v] = true;
		//cout << "VISITANDO VERTICE " << v << " COM ARESTA " << ed << endl;
		REP(i, g[v].size()){
			ii w = g[v][i];
			if(!vis[w.first]){
				if(dfs(w.first, w.second)){
					if(cycle.size() < 2 || cycle[0] != cycle[cycle.size()-1]){
						cycle.push_back(w.first);
						ans[w.second] = true;
					}
					return true;
				}
			}
			else if((w.second - MAXCL) != -(ed - MAXCL)){ //found cycle
				//cout << " ACHEI CICLO EXAMINANDO A ARESTA " << w.second << " A PARTIR DO VERTICE " << v << endl;
				cycle.push_back(w.first);
				ans[w.second] = true;
				return true;
			}
		} 
	}
	return false;
}

void dfs2(int v){
	if(valid[v]){
		vis2[v] = true;
		REP(i, g[v].size()){
			ii w = g[v][i];
			if(!vis[w.first]){
				ans[w.second] = true;
				dfs2(w.first);
			}
		}
	}
}

int main(){
	scanf(" %d %d ", &nc, &nv);
	valid.set();
	ans.reset();
	int k, x;
	REP(i, nc){
		scanf(" %d ", &k);
		REP(j, k){
			scanf(" %d ", &x);
			cl[i].push_back(x);
			inv[x+MAXCL].push_back(i);
			//cout << " X " << x << " PUSHANDO INV EM " << x+MAXCL << " O NUM " << i << endl;
		}
	}
	REPP(i, 1, nv+1){
		if(inv[i+MAXCL].size() == 1 && inv[MAXCL-i].size() == 1){
			//cout << "PUSHANDO EM " << inv[i+MAXCL][0] << " O PAR " << inv[MAXCL-i][0] << " E " << MAXCL-i << endl;
			g[inv[i+MAXCL][0]].push_back(ii(inv[MAXCL-i][0], MAXCL-i));
			g[inv[MAXCL-i][0]].push_back(ii(inv[i+MAXCL][0], i+MAXCL));
		}
		else{
			REP(j, inv[i+MAXCL].size()){
				ans[i+MAXCL] = true;
				valid[inv[i+MAXCL][j]] = false;
			}
			REP(j, inv[MAXCL-i].size()){
				ans[MAXCL-i] = true;
				valid[inv[MAXCL-i][j]] = false;
			}
		}
	}
	//REP(i, nc){
		//cout << i << " : "; REP(j, g[i].size()) cout << "(" << g[i][j].first << "," << g[i][j].second << ") ";
		//cout << endl;
	//}
	vis.reset(); 
	bool pos = true;
	REP(i, nc){
		if(valid[i] && !vis[i]){
			cycle.clear();
			cmp = 0;
			if(!dfs(i, -1)){
				if(cmp > 1){
					//cout << " POS EH FALSO POR CAUSA DA CLÁUSULA " << i << endl;
					pos = false;
				}
				else{
					ans[cl[i][0]+MAXCL] = true;
				}
			}
			else{
				vis2.reset();
				//cout << "CICLO: ";
				REP(j, cycle.size()){ 
					//cout << cycle[j] << " ";
					vis2[cycle[j]] = true;
				}
				REP(j, cycle.size()) dfs2(cycle[j]);
			}
			//cout << " NEW DFS \n";
		}
	}
	if(pos){
		printf("YES\n");
		REP(i, nc) printf("%d", (int) (ans[i+MAXCL] | (ans[-i+MAXCL] == false)));
		printf("\n");
	}
	else printf("NO\n");
	
}
