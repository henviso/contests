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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
//scanf(" %d ", &t);

int n, m, k;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
bool vis[100][100];
int total;


ii p[100][100];
vector< ii > pos;

struct INFO{
	int r, c, t;
	ii p;
	INFO(int _r, int _c, ii _p, int _t){
		r = _r;
		c = _c;
		p = _p;
		t = _t; 
	}
};

int ans;

void floodfill(){
	CLEAR0(vis); 
	total = 0; 
	ans = 0;
	queue< INFO > q; q.push(INFO(0,0, ii(-1, -1), 1));
	while(!q.empty() && pos.size() < k){
		INFO x = q.front(); q.pop();
		if(x.r < 0 || x.r >= n || x.c < 0 || x.c >= m) continue;
		if(vis[x.r][x.c]) continue;
		vis[x.r][x.c] = true;
		p[x.r][x.c] = x.p;
		//cout << " PAI " << x.r << " " << x.c << " EH " << x.p << endl;
		pos.pb(ii(x.r, x.c));
		ans += x.t;
		for(int d = 0; d<4; d++) q.push(INFO(x.r+dr[d], x.c+dc[d], ii(x.r,x.c), x.t+1));
	}
	return;
}

void printP(int r, int c){
	if(p[r][c] == ii(-1, -1)){
		cout << "(" << r+1 << "," << c+1 << ")";
		return;
	}
	printP(p[r][c].first, p[r][c].second);
	cout << " (" << r+1 << "," << c+1 << ")";
}

int main(){
	char ca;
	scanf(" %d %d %d ", &n, &m, &k);
	floodfill();
	int N = pos.size();
	cout << ans << endl;
	REPD(i, N){
		//cout << "CAM DE " << pos[i].first << " " << pos[i].second << " :";
		printP(pos[i].first, pos[i].second);
		cout << endl;
	}
}
