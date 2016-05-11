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
#include <utility>    
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
//__builtin_popcount(m)
//scanf(" %d ", &t);
//L[i]=L[i/2]+1;

int n, m;
int pd[200100][2];
int e[200100][3];
ii o[200100];
priority_queue<int> g[200100];

int solve(int k, int j){
	if(pd[k][j] == -1){
		int v = e[k][(j != 1)];
		pd[k][j] = 1;
		if(!g[v].empty()) pd[k][j] += g[v].top();
	}
	return pd[k][j];
}

void processEdge(int k){
	//cout << " PROCESANDO ARESTA {" << e[k][0] << "," << e[k][1] << "," << e[k][2] << "}\n";
	REP(j, 2){
		int v = e[k][j];
		if(j == 1 && e[k][j] == e[k][j-1]) return;
		g[v].push(solve(k, j));		
		//cout << "COLOCANDO VALOR " << solve(k, j) << " NA FILA DO " << v << endl;
	}
}

int main(){
	scanf(" %d %d ", &n, &m);
	REP(i, m){
		REP(j, 3) scanf(" %d ", &e[i][j]);
		o[i] = ii(e[i][2], i);
	}
	REP(i, m) REP(j, 2) pd[i][j] = -1;
	sort(o, o+m);
	int ans = 0;
	int i = m-1;
	while(i >= 0){
		vector< int > V;
		int x = o[i].first;
		while(o[i].first == x){
			int k = o[i].second;
			REP(j, 2){
				int x = solve(k, j); //usa a aresta k saindo do vértice j para ir para o outro vértice
				ans = max(ans, x);
				//cout << "USANDO ARESTA {" << e[k][j] << "," << e[k][(j != 1)] << "," << e[k][2] << "} ANS EH " << x << endl;
			}
			V.push_back(k); i--;
		}
		REP(i, V.size()) processEdge(V[i]);
	}
	printf("%d\n", ans);
}
