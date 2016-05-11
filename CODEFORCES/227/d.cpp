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


int g[1100][510];
int grau[1100];

int f[1100][510];
int gf[1100];

int deg[1111];
int n, m, c;
int mate[1111]; 
bitset<1111> vis;

bool aug(int v){
	if(vis[v]) return false;
	vis[v] = true;
	//cout << " VISITANDO " << v-1 << endl;
	REP(i, grau[v]){
		int w = g[v][i];
		//cout << " W EH " << w << endl;
		if(mate[w] == 0 || aug(mate[w])){
			mate[w] = v;
			return true;
		}
	}
	return false;
}


int MCBM(){
	CLEAR0(mate);
	int ans = 0;
	REPP(i, 1, n+1){
		vis.reset();
		ans += aug(i);
	}
	return ans;
}

int main(){
	CLEAR0(deg);
	CLEAR0(gf);
	scanf(" %d %d ", &n, &m);
	int u, v;
	REP(i, m){
		scanf(" %d %d ", &u, &v);
		deg[u]++;
		f[u][gf[u]++] = v;
		if(v != u) deg[v]++;
	}
	int ans = INF;
	for(c = 1; c<=n; c++){
		REPP(i, 1, n+1){
			grau[i] = 0;
			if(i == c) continue;
			REP(j, gf[i]){
				if(f[i][j] != c) g[i][grau[i]++] = f[i][j];
			}
		}
		
		/*cout << " G EH " << endl;
		REPP(i, 1, n){
			cout << i << ":";
			REP(j, grau[i]) cout << " " << g[i][j];
			cout << endl;
		}*/
		
			
		int tans = (2 * n - 1 - deg[c]);
		
		int other = m-deg[c];
		int aux = MCBM();
		
		//cout << "MCB EM " << c << " EH " << aux << endl;
		tans += other - 2*aux + (n-1);
		//cout << " PRA AJUSTAR " << c << " EH "  << tans << endl;
		ans = min(tans, ans);
	}
	printf("%d\n", ans);
	//cout << " NR PRIMOS " << primes.size() << " " << primes[primes.size()-1] << endl;
}
