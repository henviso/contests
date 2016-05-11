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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n;
int s;
int f[200100];
vi g[200100];
int col[200100];
bitset<200100> used;

void dfs(int u){
	col[u] = 0;
	stack<int> st;
	st.push(u);
	while(!st.empty()){
		int v = st.top(); bool ps = false; 
		REP(i, g[v].size()){
			int w = g[v][i];
			if(col[w] == -1){
				col[w] = 0;
				st.push(w);
				ps = true;
			}
		}
		if(ps) continue;
		else{
			used.reset();
			REP(i, g[v].size()){
				int w = g[v][i];
				used[col[w]] = true;
			}
			REPP(i, 1, n+1) if(!used[i]){ col[v] = i; break; }
			st.pop();
		}
	}
}

int main(){
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		scanf(" %d ", &n);
		f[0] = -1;
		col[0] = 0;
		REP(i, n+1) g[i].clear();
		REPP(i, 1, n+1){
			scanf(" %d ", &f[i]);
			col[i] = -1;
			if(f[i] == 0) s = i;
			g[f[i]].push_back(i);
		}
		ll ans = 0LL;
		dfs(s);
		REPP(i, 1, n+1){
			ans += col[i];
		}
		cout << "Case #" << ca << ": " << ans << endl;
	}
}
