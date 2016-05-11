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

int n;
char a[110][110];
string v[2] = {"abcdefghij", "ABCDEFGHIJ"};
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
	
int bfs(string s){
	bool used[300]; CLEAR0(used);
	REP(i, s.length()) used[s[i]] = true;
	int D[110][110];
	CLEAR(D, INF); 
	queue< ii > q;
	
	if(used[a[0][0]]){ D[0][0] = 1; q.push(mp(0, 0));}
	while(!q.empty()){
		ii u = q.front(); q.pop();
		for(int d = 0; d<4; d++){
			int r = u.first +dr[d];
			int c = u.second +dc[d];
			if(r < 0 || r >= n || c < 0 || c >= n || !used[a[r][c]]) continue;
			if(D[r][c] == INF){
				q.push(mp(r, c));
				D[r][c] = D[u.first][u.second]+1;
			}
		}
	}
	return D[n-1][n-1];
}

int main(){
	while(scanf(" %d ", &n) != EOF){
		REP(i, n) REP(j, n){
			scanf(" %c ", &a[i][j]);	
		}
		int ans = INF;
		REP(msk, (1 << 10)){
			string s = "";
			REP(i, 10) s += v[((msk&(1<<i)) != 0)][i];
			//cout << " S " << s << endl;
			ans = min(ans, bfs(s));
		}
		if(ans == INF) ans = -1;
		printf("%d\n", ans);
	}
}
