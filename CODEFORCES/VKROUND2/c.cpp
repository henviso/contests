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
#include <utility>    
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
//L[i]=L[i/2]+1;

int n, m, q;
int a[111][111];
int b[111][111];

void shift_row(int r){
	int x = b[r][0];
	REP(i, m-1) b[r][i] = b[r][i+1];
	b[r][m-1] = x;
}

void shift_col(int c){
	int x = b[0][c];
	REP(i, n-1) b[i][c] = b[i+1][c];
	b[n-1][c] = x;
}

int main(){
	scanf(" %d %d %d ", &n, &m, &q);
	int t, r, c, x;
	CLEAR0(a);
	REP(i, n)
	REP(j, m) b[i][j] = i*m+j;
	REP(i, q){
		scanf(" %d ", &t);
		if(t == 1){
			scanf(" %d ", &r);
			shift_row(r-1);
		}
		else if(t == 2){
			scanf(" %d ", &c);
			shift_col(c-1);
		}
		else{
			scanf(" %d %d %d ", &r, &c, &x); r--; c--;
			int nr = b[r][c]/m;
			int nc = b[r][c]%m;
			a[nr][nc] = x;
		}
	}
	REP(i, n){
		printf("%d", a[i][0]);
		REPP(j, 1, m) printf(" %d", a[i][j]);
		printf("\n");
	}
	
}
