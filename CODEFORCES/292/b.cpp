#include <iostream>
#include <cstdio>
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
#include <cstring>
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

#define MAXN 4000100
#define MAXE 4
#define VERT(i, j) 1+(i-1)*m+(j-1)

char a[2010][2010];
char b[2010][2010];
int c[2010][2010];
int g[MAXN][MAXE];
int grau[MAXN];
bitset<MAXN> used;
int V, n, m;
queue<int> q;


void parear(int u, int v){
	if(u > v) swap(u, v);
	int r, c;
	if(u+m > v){
		r = ((u-1)/m)+1, c = ((u-1)%m)+1;
		b[r][c] = '<';
		r = ((v-1)/m)+1, c = ((v-1)%m)+1;
		b[r][c] = '>';
	}
	else{
		r = ((u-1)/m)+1, c = ((u-1)%m)+1;
		b[r][c] = '^';
		r = ((v-1)/m)+1, c = ((v-1)%m)+1;
		b[r][c] = 'v';
	}
}

void remove(int v){
	REP(i, grau[v]){
		int u = g[v][i];
		REP(j, grau[u]) if(g[u][j] == v){ 
			for(int k = 0; j+k<grau[u]-1; k++) g[u][j+k] = g[u][j+k+1];
			grau[u]--; 
			break;
		}
		if(grau[u] == 1){
			q.push(u);
		}
	}
	grau[v] = 0;
}

int main(){
	cin >> n >> m;
	CLEAR0(a);
	CLEAR0(grau);
	int livres = 0;
	REPP(i, 1, n+1) scanf(" %s ", &a[i][1]);
	REPP(i, 1, n+1)
	REPP(j, 1, m+1){
		int v = VERT(i, j);
		int d = 0;
		if(a[i][j] == '.'){
			livres++;
			if(a[i][j+1] == '.'){
				g[v][grau[v]++] = VERT(i, j+1);
			}
			if(a[i][j-1] == '.'){
				g[v][grau[v]++] = VERT(i, j-1);
			}
			if(a[i+1][j] == '.'){
				g[v][grau[v]++] = VERT(i+1, j);
			}
			if(a[i-1][j] == '.'){
				g[v][grau[v]++] = VERT(i-1, j);
			}
		}
		else b[i][j] = '*';
		if(grau[v] == 1) q.push(v);
	}
	bool pos = true;
	used.reset();
	int matched = 0;
	while(!q.empty()){
		int v = q.front(), u = -1; q.pop();
		if(used[v]) continue;
		REP(i, grau[v]){
			u = g[v][i];
			if(!used[u]){
				break;
			}
		}
		if(u != -1){
			parear(v, u);
			used[v] = used[u] = true;
			remove(v);
			remove(u);
			matched += 2;
		}
		else{ pos = false; break; }
	}
	if(pos && matched == livres){
		REPP(i, 1, n+1){
			REPP(j, 1, m+1) printf("%c", b[i][j]);
			printf("\n");
		}
	}
	else{
		printf("Not unique\n");
	}
	
}
