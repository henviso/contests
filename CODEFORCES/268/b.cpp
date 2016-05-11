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

int n, a, b, cnt;
map<int, int> idx;
int v[100100];
vi g[100100];
bitset<100100> ans;
bitset<100100> vis;

int dfs(int s, bool sturn){
	vis[s] = true;
	cnt++;
	REP(i, g[s].size()){
		int u = g[s][i];
		if(!vis[u]){
			if(sturn) ans[s] = ans[u] = ((v[s] + v[u]) == b);
			dfs(u, !sturn);
		}
	}
}

int main(){
	cin >> n >> a >> b;
	bool pos;
	REP(i, n){
	   cin >> v[i];
	   idx[v[i]] = i;
	}
	
	REPD(msk, 4){
		vis.reset();
		int A = -1, B = -1;
		if(msk&1 && (a%2 == 0) && idx.count(a/2)){ A = a/2; }
		if(msk&2 && (b%2 == 0) && idx.count(b/2)){ B = b/2; }
		REP(i, n){
		   int x = v[i];
		   if(x == A || x == B){
			   if(x == A) ans[i] = 0;
			   else if(x == B) ans[i] = 1;
			   vis[i] = true;
			   continue;
		   }
		   if((a-x) != x && idx.count(a-x)) g[i].push_back(idx[a-x]);
		   if(a != b && (b-x) != x && idx.count(b-x)) g[i].push_back(idx[b-x]);
		}
		pos = true;
		REP(i, n){
			if(vis[i]) continue;
			if(g[i].size() == 0){ pos = false; break; }
			if(g[i].size() == 1){		
				cnt = 0;
				dfs(i, true);
				if(cnt%2) pos = false;
			}
		}
		REP(i, n){
			if(vis[i]) continue;
			cnt = 0;
			dfs(i, true);
			if(cnt%2) pos = false;
		}
		if(pos){
			cout << "YES\n";
			cout << ans[0];
			REPP(i, 1, n) cout << " " << ans[i];
			cout << endl;
			break;
		}
	
		//cout << " MSK " << msk << " A " << A << " B " << B << " POS " << pos << endl;
		//if(A >= 0) cout << " VISA " << vis[A] << endl;
		//if(B >= 0) cout << " VISB " << vis[B] << endl; 
	}
	if(!pos) cout << "NO\n";
}
