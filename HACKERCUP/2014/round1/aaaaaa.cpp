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
#include <climits>
#include <cfloat>
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
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
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
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);


int t, n, m;
char p[600][600];
bitset<2> vis[600][600]; //0 CIMA, 1 ESQ

int lp[600][600];

int dr[] = {0,1};
int dc[] = {1,0};
int ans;

bool valid(int r, int c){
	if(r < 0 || r >= n || c < 0 || c >= m || p[r][c] == '#') return false;
	return true;
}

int getlp(int r, int c){ //RET LONGEST PATH
	if(lp[r][c] == -1){
		lp[r][c] = 0;
		for(int d = 0; d<2; d++){
			int nr = r+dr[d], nc = c+dc[d];
			if(!valid(nr, nc)) continue;
			lp[r][c] = max(getlp(nr, nc)+1, lp[r][c]);
		}
		ans = max(ans, lp[r][c]);
	}
	//cout << " LP " << r << " " << c << " " << lp[r][c] << endl;
	return lp[r][c];
}

void floodfill(int r, int c, bool up){
	//cout << " TO EM " << r << " " << c << " UP " << up << " AINDA NAO SEI " << endl;
	if(!valid(r,c) || vis[r][c][up]) return;
	if(up) vis[r][c][1] = true;
	else vis[r][c][0] = true;
	//cout << " TO EM " << r << " " << c << " UP " << up << " LP EH " << getlp(r, c) << endl;
	int dis = r+c+getlp(r,c);
	if(up){
		REPP(k, 1, m){
			//cout << "indo para a esquerda k = " << k << " DIS " << dis << endl;
			int nr = r, nc = c-k;
			if(!valid(nr, nc)) break;
			dis = max(dis, r+c+k);
			if(valid(nr+1, nc)){
				dis = max(dis, r+c+k+getlp(nr+1, nc)+1); 
			}
		} 
	}
	else{
		REPP(k, 1, n){
			//cout << "indo para a cima k = " << k << " DIS " << dis << endl;
			int nr = r-k, nc = c;
			if(!valid(nr, nc)) break;
			dis = max(dis, r+c+k);
			if(valid(nr, nc+1)){
				//cout << " ALT " << " EM " << nr << " " << nc+1 << " LP " << getlp(nr, nc+1) << " DIS " << r+c+k+getlp(nr, nc+1)+1 << endl;
				dis = max(dis, r+c+k+getlp(nr, nc+1)+1); 
			}
		}
	}
	ans = max(ans, dis);
	//cout << " DIS EM " << r << " "  << c << " " << dis << endl;
	for(int d = 0; d<2; d++){
		//cout << " CHAMANDO " << r+dr[d] << " " << c+dc[d] << " VIS " << vis[r+dr[d]][c+dc[d]][0] << " E " << vis[r+dr[d]][c+dc[d]][1] << endl;
		floodfill(r+dr[d], c+dc[d], d);
	}
	return;
}

void solve(){
	REP(i, n) REP(j, m) lp[i][j] = -1;
	getlp(0,0);
	ans = 0;
	floodfill(0,0,0);
	floodfill(0,0,1);
	return;
}

int main(){
	scanf(" %d ", &t);
	REP(ca, t){
		scanf(" %d %d ", &n, &m);
		REP(i, n) REP(j, m) REP(k, 2) vis[i][j][k] = 0;
		REP(i, n){
			REP(j, m) scanf(" %c ", &p[i][j]);
		}
		solve();
		cout << "Case#" << ca+1 << ": " << ans+1 << endl;
	}
}

