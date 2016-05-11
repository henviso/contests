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

bitset<300000> col, vis;
int n;
vi g[300000];
vector< ll > a;

#define MOD 1000000007LL

ll pd[300000][2];

void dfs(int s){
	vis[s] = true;
	if(col[s]){ pd[s][1] = 1LL; pd[s][0] = 0LL; }
	else{ pd[s][0] = 1LL; pd[s][1] = 0LL; }
	REP(i, g[s].size()){
		int u = g[s][i];
		if(!vis[u]){
			dfs(u);
			pd[s][1] *= (pd[u][0] + pd[u][1]);
			pd[s][1] += (pd[s][0] * pd[u][1]);
			pd[s][1] %= MOD;
			pd[s][0] = (pd[s][0]*(pd[u][0] + pd[u][1]))%MOD;
		}
	}		
}

int main(){
	cin >> n;
	int x;
	REP(i, n-1){ 
		cin >> x;
		g[(i+1)].push_back(x);
		g[x].push_back((i+1));
	}
	REP(i, n){
		cin >> x;
		col[i] = (x == 1);
	}
	vis.reset();
	dfs(0);
	cout << pd[0][1] << endl;
}
