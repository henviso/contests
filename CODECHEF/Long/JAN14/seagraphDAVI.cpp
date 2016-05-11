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

#define MAXN 110
#define MAXM MAXN*MAXN

int n,m;
int adj[MAXN][MAXN], nadj[MAXN], from[MAXM], to[MAXM];
int mate[MAXN], first[MAXN], label[MAXN];
queue<int> q;
#define OUTER(x) (label[x] >= 0)
void L(int x, int y, int nxy) {
int join, v, r = first[x], s = first[y];
if (r == s) return;
nxy += n + 1;
label[r] = label[s] = -nxy;
while (1) {
if (s != 0) swap(r,s);
r = first[label[mate[r]]];
if (label[r] != -nxy) label[r] = -nxy;
else {
join = r;
break;
}
}
v = first[x];
while (v != join) {
if (!OUTER(v)) q.push(v);
label[v] = nxy; first[v] = join;
v = first[label[mate[v]]];
}
v = first[y];
while (v != join) {
if (!OUTER(v)) q.push(v);
label[v] = nxy; first[v] = join;
v = first[label[mate[v]]];
}
for (int i = 0; i <= n; i++) {
if (OUTER(i) && OUTER(first[i])) first[i] = join;
}
}
void R(int v, int w) {
int t = mate[v]; mate[v] = w;
if (mate[t] != v) return;
if (label[v] >= 1 && label[v] <= n) {
mate[t] = label[v];
R(label[v],t);
return;
}
int x = from[label[v]-n-1];
int y = to[label[v]-n-1];
R(x,y); R(y,x);
}
int E() {
memset(mate,0,sizeof(mate));
int r = 0;
bool e7;
for (int u = 1; u <= n; u++) {
memset(label,-1,sizeof(label));
while (!q.empty()) q.pop();
if (mate[u]) continue;
label[u] = first[u] = 0;
q.push(u); e7 = false;
while (!q.empty() && !e7) {
int x = q.front(); q.pop();
for (int i = 0; i < nadj[x]; i++) {
int y = from[adj[x][i]];
if (y == x) y = to[adj[x][i]];
if (!mate[y] && y != u) {
mate[y] = x; R(x,y);
r++; e7 = true;
break;
}
else if (OUTER(y)) L(x,y,adj[x][i]);
else {
int v = mate[y];
if (!OUTER(v)) {
label[v] = x; first[v] = y;
q.push(v);
}
}
}
}
label[0] = -1;
}
return r;
}

int main() {
	int t, u, v;
	scanf(" %d ", &t);
	while(t--){
		CLEAR0(nadj);
		scanf(" %d %d ",&n ,&m);
		REP(i, m){
			scanf(" %d %d ",&u ,&v);
			adj[u][nadj[u]++] = i;
			adj[v][nadj[v]++] = i;
			from[i] = u; to[i] = v;
		}
		cout << " PORRA " << E() << endl;
	}
}
