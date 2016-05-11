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
#include <iomanip>
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
#define EPS 0.000000000001L
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

int n, m;
vi g[600];
bitset<1000> vis;

long double ans = -1000000000000000000.0L;
long double vv[600];
long double ev[600][600];

vi taken;
priority_queue< pair< long double, ii > > pq;

void process(int vtx){
    taken[vtx] = 1;
    REP(j, g[vtx].size()){
        int u = vtx, v = g[vtx][j];
        pair<long double, ii > x = make_pair(vv[v]/ev[u][v], ii(u, v));
        if(!taken[v]) pq.push(x);
    }
}

void prim(int v){
    taken.assign(n, 0);
    process(v);
    long double V = vv[v];
    long double E = 0.0L;
    long double tans = 0.0L;
    //cout << " COMEÇANDO NO VERT " << v << endl;
    while(!pq.empty() && fabs(pq.top().first - tans) > EPS && pq.top().first > tans){
        pair<long double, ii > f = pq.top(); pq.pop();
        ii x = f.second;
       // cout << " TOPO EH " << f.first << " " << x.first << " " << x.second << endl; 
        if(!taken[x.second]){
            V += vv[x.second];
            E += ev[x.first][x.second];
            tans = V/E;
            //cout << " TANS " << tans << " V " << V << " E " << E << endl; 
            if(fabs(ans-tans) > EPS && tans > ans) ans = tans;
            process(x.second);
        }
    }
    while(!pq.empty()) pq.pop();
}

int main(){
    cin >> n >> m;
    
    int u, v;
    int w;
        
    REP(i, n){
        int aux;
        scanf(" %d ", &aux);
        vv[i] = (long double) aux;
    }
    REP(i, m){
        scanf(" %d %d %d ", &u, &v, &w);
        u--;
        v--;
        ev[u][v] = ev[v][u] = (long double) w;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    REP(i, n) prim(i);
    if(fabs(ans - 0.0L) <= EPS || ans < 0.0L){
        printf("0.000000000000000\n");
    }
    else{
		 cout << fixed;
         cout << setprecision(15) << ans << endl;
    }
}
