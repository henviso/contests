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
#define MOD 1000003LL
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
#define EPS 10e-20
//__builtin_popcount(m)
//scanf(" %d ", &t);

int T, n, m, k;
int a[200100];

int t[210][210];

int pd[200100][210];

int main(){
	scanf(" %d ", &T);
	while(T--){
		
		scanf(" %d %d %d ", &m, &k, &n);
		
		CLEAR(pd, INF);
		CLEAR0(t);
		REPP(i, 1, m+1){ pd[0][i] = 0; t[i][i] = true;}
		int x, y;
		REP(i, k){
			scanf(" %d %d ", &x, &y);
			t[x][y] = t[y][x] = true;
		}
		REPP(k, 1, m+1)	
		REPP(i, 1, m+1)
		REPP(j, 1, m+1)
		t[i][j] |= (t[i][k] && t[k][j]);
		REPP(i, 1, n+1) scanf(" %d ", &a[i]);
		
		REPP(i, 1, n+1){
			REPP(j, 1, m+1){
				pd[i][j] = min(pd[i][j], pd[i][j-1]); 
				if(t[a[i]][j]) pd[i][j] = min(pd[i][j], pd[i-1][j] + (j != a[i]));
			}
		}
		int ans = pd[n][m];
		if(ans >= INF) printf("-1\n");
		else printf("%d\n", ans);
	}
}
