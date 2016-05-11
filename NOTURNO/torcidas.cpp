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
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
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
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
int ma[1100][1100];
int g[1100][1100];
int grau[1100];
char str[2000];
bitset<2000> vis;
vi comp;

void dfs(int s){
	vis[s] = true;
	comp.push_back(s);
	REP(j, grau[s]){
		int w = g[s][j];
		if(!vis[w]) dfs(w);
	}
}

int main(){
		while(1){
			scanf(" %d ", &n);
			if(n == 0) break;
			CLEAR0(grau);
			REP(i, n){
				scanf(" %s ", &str[0]);
				REP(j, n) 
				if(str[j] == '1'){
					g[i][grau[i]++] = j;
					g[j][grau[j]++] = i;
					ma[i][j] = ma[j][i] = 1;
				}
				else ma[i][j] = ma[j][i] = 0;
			}
			vis.reset();
			
			bool pos = true;
			int ans = 0;
			REP(i, n) if(!vis[i]){
				dfs(i);
				REP(j, comp.size()){
					REPP(k, j+1, comp.size()){
						int a = comp[j], b = comp[k];
						if(ma[a][b] == 0) pos = false;
					}
				}
				ans++;
				comp.clear();
			}
			if(pos) printf("%d\n", ans);
			else printf("impossivel\n");
		}
}

