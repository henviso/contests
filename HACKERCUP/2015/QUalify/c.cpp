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

int t, n, m;
char a[200][200][4];

int s, T;

vi g[50000];
bitset<50000> vis;

int h[300];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int forb[] = {'v', '<', '^', '>'};

bool blockable(char c){
	if(c == '.' || c == 'S' || c == 'G') return false;
	return true;	
}

bool reachable(int r, int c, int k){
	if(blockable(a[r][c][k])) return false;
	REP(l, 4){
		REPP(i, 1, 101){
			int nr = r+dr[l]*i, nc = c+dc[l]*i;
			if(min(nr, nc) < 0 || nr >= n || nc >= m) break;
			if(a[nr][nc][k] == forb[l]) return false;
			if(blockable(a[nr][nc][k])) break;
		}
	}
	return true;
}

int bfs(){
	vis.reset();
	queue<int> q; q.push(s); vis[s] = true; q.push(-1); 
	int d = 0;
	while(!q.empty()){
		int f = q.front(); q.pop();
		//cout << " F " << f << endl;
		if((f%(n*m)) == T) return d;
		if(f == -1){
			if(!q.empty()){ d++; q.push(-1); continue; }
			else return -1;
		}
		else{
			REP(i, g[f].size()){
				int w = g[f][i]; 
				if(vis[w]) continue;
				q.push(w);
				vis[w] = true;
			}
		}
	}
}

int main(){
	h['^'] = 2; h['>'] = 3;	h['v'] = 0; h['<'] = 1; 
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		scanf(" %d %d ", &n, &m);
		REP(i, n) REP(j, m){
			scanf(" %c ", &a[i][j][0]);
			if(a[i][j][0] == 'S') s = i*m+j;
			else if(a[i][j][0] == 'G') T = i*m+j;
		}
		REPP(k, 1, 4){
			REP(i, n)
			REP(j, m) 
			if(!blockable(a[i][j][0]) || a[i][j][0] == '#') a[i][j][k] = a[i][j][0]; 
			else a[i][j][k] = forb[((h[a[i][j][0]]+k)%4)];
		}
		REP(i, 4*n*m) g[i].clear();
		REP(i, n)
		REP(j, m){
			if(blockable(a[i][j][0]) || a[i][j][0] == 'G') continue;
			REP(k, 4){
				int v = k*n*m + m*i + j;
				REP(l, 4){
					int r = i+dr[l], c = j+dc[l];
					if(min(r, c) < 0 || r >= n || c >= m) continue;
					if(reachable(r, c, (k+1)%4)){
						int w = ((k+1)%4)*n*m + m*r + c;
						g[v].push_back(w);
					}
				}
			}
		}
		int ans = bfs();
		if(ans == -1) cout << "Case #" << ca << ": impossible\n";
		else cout << "Case #" << ca << ": " << ans << endl;
	}
}
