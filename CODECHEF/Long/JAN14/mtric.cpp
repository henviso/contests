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

int n, m;
int g[110][110], grau[1000], from[1000], to[1000];
int mate[110], first[110], label[110];
int fila[1000], ini, fim;

void pair_link(int x, int y, int l) {
	int join, v, r = first[x], s = first[y];
	if(r == s) return;
	l += n + 1;
	label[r] = label[s] = -l;
	while(true){
		if(s != 0) swap(r,s);
		r = first[label[mate[r]]];
		if(label[r] != -l) label[r] = -l;
		else{
			join = r;
			break;
		}
	}
	v = first[x];
	while(v != join) {
		if(label[v] < 0) fila[fim++] = v;
		label[v] = l; first[v] = join;
		v = first[label[mate[v]]];
	}
	v = first[y];
	while(v != join){
		if(label[v] < 0) fila[fim++] = v;
		label[v] = l; first[v] = join;
		v = first[label[mate[v]]];
	}
	REP(i, n+1) if((label[i] >= 0) && (label[first[i]] >= 0)) first[i] = join;
	
}

void rematch(int v, int w) {
	int t = mate[v]; mate[v] = w;
	if(mate[t] != v) return;
	if(1 <= label[v] && label[v] <= n){
		mate[t] = label[v];
		rematch(label[v],t);
		return;
	}
	int x = from[label[v]-n-1];
	int y = to[label[v]-n-1];
	rematch(x,y); rematch(y,x);
}

bool matchable(){
	if(n%2) return false;
	REPP(i, 1, n+1) if(grau[i] == 0) return false;
	
	CLEAR0(mate);
	int r = 0;
	bool aug;
	REPP(u, 1, n+1){
		CLEAR(label, -1);
		ini = fim = 0;
		if (mate[u]) continue;
		label[u] = first[u] = 0;
		fila[fim++] = u;
		aug = false;
		while(ini != fim && !aug){
			int x = fila[ini++];
			REP(i, grau[x]){
				int y = from[g[x][i]];
				if(y == x) y = to[g[x][i]];
				if(!mate[y] && y != u) {
					mate[y] = x; rematch(x,y);
					r++; aug = true;
					break;
				}
				else if(label[y] >= 0) pair_link(x,y,g[x][i]);
				else{
					int v = mate[y];
					if(label[v] < 0){
						label[v] = x; first[v] = y;
						fila[fim++] = v;
					}
				}
			}
		}
		label[0] = -1;
	}
	return (r == n/2);
}


int main() {
	int t, u, v;
	scanf(" %d ", &t);
	while(t--){
		CLEAR0(grau);
		scanf(" %d %d ",&n ,&m);
		REP(i, m){
			scanf(" %d %d ",&u ,&v);
			g[u][grau[u]++] = i;
			g[v][grau[v]++] = i;
			from[i] = u; to[i] = v;
		}
		if(matchable()) printf("YES\n");
		else printf("NO\n");
	}
}
