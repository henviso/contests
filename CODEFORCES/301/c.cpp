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

int n, m;
vi g[600];
char a[600][600];
bool vis[600][600];
int r1, r2, c1, c2;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
bool pos = false;
	

void dfs(int r, int c){
	vis[r][c] = true;
	if(r == r2 && c == c2) pos = true;
	if(a[r][c] == 'X') return;
	REP(k, 4){
		int nr = r+dr[k], nc = c+dc[k];
		if(nr < 0 || nr >=n || nc < 0 || nc >= m) continue;
		if(!vis[nr][nc]) dfs(nr, nc);
	}
}

int main(){
	cin >> n >> m;
	REP(i, n) scanf(" %s ", &a[i][0]);
	cin >> r1 >> c1; r1--; c1--;
	cin >> r2 >> c2; r2--; c2--;
	//cout << "n "<< n << " m " << m << endl;
	//cout << "r1 " << r1 << " c1 " << c1  << "r2 " << r2 << " c2 " << c2 << endl;
			
	
	CLEAR0(vis); a[r1][c1] = '.';
	if(a[r2][c2] == 'X'){
		dfs(r1, c1);
	}
	else{
		REP(k, 4){
			int nr = r2+dr[k], nc = c2+dc[k];
			if(nr < 0 || nr >=n || nc < 0 || nc >= m || a[nr][nc] == 'X' || (nr == r1 && nc == c1)) continue;
			vis[nr][nc] = true;
			dfs(r1, c1);
			CLEAR0(vis);
		}	
	}
	if(pos) cout << "YES\n";
	else cout << "NO\n";
	
}
