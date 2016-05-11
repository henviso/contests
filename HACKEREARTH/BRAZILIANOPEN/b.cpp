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
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n, m;
int a[2010][2010];
bool vis[2010][2010];
ii q[1000100];

int cc;
int dr[] = {1,1,1,0,0,-1,-1,-1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		REP(i, n)
		REP(j, m) scanf("%d", &a[i][j]);
		CLEAR0(vis);
		int ncc = 0;
		int ans = 0;
		REP(i, n)
		REP(j, m) if(a[i][j] == 1 && !vis[i][j]){
			ncc++;
			cc = 1;
			vis[i][j] = 1;
			int ini;
			ini = 0;
			q[ini++] = ii(i, j);
			while(ini){
				ii f = q[--ini], p;
				for(int d = 0; d<8; d++){
					ii p = ii(f.first + dr[d], f.second + dc[d]);
					if(p.first < 0 || p.first >= n || p.second < 0 || p.second >= m || 
					   a[p.first][p.second] == 0 || vis[p.first][p.second]) continue;
					vis[p.first][p.second] = 1; cc++;
					q[ini++] = p;
				}
			}
			ans = max(ans, cc);
		}
		cout << ncc << " " << ans << endl;
	}
}
