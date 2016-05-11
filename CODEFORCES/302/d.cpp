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

struct STATE{
	int x, y, z;
	STATE(int _x, int _y, int _z){
		x = _x; z = _z; y = _y;
	}
};

double pd[110][110][110];
bool vis[110][110][110];
queue<STATE> q; 
int r, s, p;

void comp(STATE S){
	vis[S.x][S.y][S.z] = true;
	double X = S.x, Y = S.y, Z = S.z;
	double t = X*Y + Y*Z + X*Z;
	if(S.x > 0 && t > EPS){
		pd[S.x-1][S.y][S.z] += pd[S.x][S.y][S.z] * ((X*Z) / t);
		S.x--; q.push(S); S.x++;
	}
	if(S.y > 0 && t > EPS){
		pd[S.x][S.y-1][S.z] += pd[S.x][S.y][S.z] * ((X*Y) / t);
		S.y--; q.push(S); S.y++;
	}
	if(S.z > 0 && t > EPS){
		pd[S.x][S.y][S.z-1] += pd[S.x][S.y][S.z] * ((Y*Z) / t);
		S.z--; q.push(S); S.z++;
	}
}

int main(){
	cin >> r >> s >> p;
	REP(i, r+1)
	REP(j, s+1)
	REP(k, p+1) pd[i][j][k] = 0.0;
	pd[r][s][p] = 1.0;
	CLEAR0(vis);
	STATE S(r, s, p);
	q.push(S);
	while(!q.empty()){
		S = q.front(); q.pop();
		if(!vis[S.x][S.y][S.z]){
			comp(S);
		}
	}
	double a = 0.0, b = 0.0, c = 0.0;
	REPP(i, 1, r+1) a += pd[i][0][0];
	REPP(j, 1, s+1) b += pd[0][j][0];
	REPP(k, 1, p+1) c += pd[0][0][k];
	printf("%.12lf %.12lf %.12lf\n", a, b, c);
}

