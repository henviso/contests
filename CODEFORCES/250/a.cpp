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

int n, m;
vi gd[2010];
vi gu[2010];
ll v[2010], ans;
bitset<2010> vis;
bitset<2010> rem; 

ll remove(int x){
    rem[x] = true;
    ll sum = 0LL;
    REP(i, gu[x].size()){
        int u = gu[x][i];
        if(!rem[u]) sum += v[u];
    }
    return sum;
}

void dfs(int s){
	vis[s] = true;
    REP(j, gd[s].size()){
        int u = gd[s][j];
        if(!vis[u]) dfs(u);
    }
    ans += remove(s);
}

int main(){
    cin >> n >> m;
    REPP(i, 1, n+1){
        cin >> v[i];
    }
    int u, w;
    REP(i, m){
        cin >> u >> w;
        if(v[u] <= v[w]) gd[u].push_back(w);
        else gd[w].push_back(u);
        gu[u].push_back(w);
        gu[w].push_back(u);
    }
    
    
    rem.reset();
    vis.reset();
    ans = 0LL;
    REPP(i, 1, n+1) if(!vis[i]) dfs(i);
    
    cout << ans << endl;
        
}
