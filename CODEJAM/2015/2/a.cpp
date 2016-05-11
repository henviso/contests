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
#include <unistd.h>
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

int t, r, c;
char a[200][200];
bool vis[200][200];
bool cycle[200][200];
int dx[4] = { 0, -1, 1, 0};
int dy[4] = { -1, 0, 0, 1};
int dc[4] = {'^', '<', '>', 'v'}; 
int h[300];

bool validCel(int y, int x){
	return (y < r && x < c && y >= 0 && x >= 0);
}

bool dfs(int y, int x){
	REP(k, 4){
		if(dc[k] == a[y][x]){
			if(vis[y][x]) return true;
			vis[y][x] = true;
			y += dy[k]; x += dx[k];
			while(validCel(y, x) && a[y][x] == '.'){y += dy[k]; x += dx[k];}
			if(validCel(y, x)) return dfs(y, x);
			return false;
		}
	}
	return false;
}

int bestChoice(int y, int x){
	
	
}

int main(){
	h['^'] = 0;
	h['<'] = 1;
	h['>'] = 2;
	h['v'] = 3;
	cin >> t; 
	REPP(tc, 1, t+1){
		cin >>  r >> c;
		REP(i, r) REP(j, c) scanf(" %c ", &a[i][j]);
		REP(i, r) REP(j, c){
			if(cycle[i][j]) continue;
			CLEAR0(vis);
			bool ok = dfs(i, j);
			if(ok){
				REP(nr, r) REP(nc, c) if(vis[nr][nc]) cycle[nr][nc] = true;
			}	
		}
		int ans = 0;
		REP(i, r) REP(j, c){
			if((a[i][j] != '.') && (cycle[i][j] == false)){
				bool pos = false;
				REP(k, 4){
					if(dc[k] != a[i][j]){
						int K = k;
						int nr = i+dy[K], nc = j+dx[K];
						while(validCel(nr, nc) && cycle[nr][nc] == false){
							while(validCel(nr, nc) && a[nr][nc] == '.'){
								nr += dy[K]; nc += dx[K];
							}
							if(validCel(nr, nc)) K = h[a[nr][nc]];
						}
						if(validCel(nr, nc)){
							ans++; pos = true; break;
						}
					}
				}
				if(!pos){
					ans = -1; break;
				}
			}
		}
		if(ans == -1) cout << "Case #" << tc << ": IMPOSSIBLE\n";
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
