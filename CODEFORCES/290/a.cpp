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

#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2


int n;
string s[1000];

bool pos = true;
vi g[300], dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;

void test(int a, int b){
	int N = max(s[a].length(), s[b].length());
	REP(i, N){
		if(i < s[a].length() && i < s[b].length()){
			if(s[a][i] != s[b][i]){
				g[s[a][i]].push_back(s[b][i]);
				return;
			}
		}
		else{
			if(i < s[a].length()){
				pos = false;
				return;
			}
		}
	}
}

void SCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	REP(j, g[u].size()){
		int v = g[u][j];
		if(dfs_num[v] == UNVISITED) SCC(v);
		if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		numSCC++;
		while(true){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			//printf(" %d ", v);
			if(u == v) break;
		}
	}
}

vi ts;

void dfs(int u){
	dfs_num[u] = VISITED;
	REP(j, g[u].size()){
		int v = g[u][j];
		if(dfs_num[v] == UNVISITED) dfs(v);
	}
	ts.push_back(u);
}

int main(){
	cin >> n;
	REP(i, n) cin >> s[i];
	REP(i, n-1) test(i, i+1);
	dfs_num.assign(300, UNVISITED);
	dfs_low.assign(300, 0);
	visited.assign(300, 0);
	dfsNumberCounter = numSCC = 0;
	REP(i, 300) if(dfs_num[i] == UNVISITED) SCC(i);
	if(numSCC < 300) pos = false;
	if(pos){
		dfs_num.assign(300, UNVISITED);
		REPP(i, 'a', 'z'+1) if(dfs_num[i] == UNVISITED) dfs(i);
		reverse(ts.begin(), ts.end());
		REP(i, ts.size()){
			cout << ((char) ts[i]);
		}
		cout << endl;
	}
	else cout << "Impossible\n";
	
}
