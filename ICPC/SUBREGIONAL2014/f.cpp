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
typedef vector<vector<int> > matrix;
const int MOD = 10000;
int n, l, s, t;
matrix M; 

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(n, vector<int>(n));
    REP(i, n) REP(j, n) REP(k, n)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
	 
// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}


int main(){
	while(scanf(" %d %d ", &n, &l) != EOF){
		scanf(" %d %d ", &s, &t);
		M.resize(n);
		REP(i, n) M[i].assign(n, 0);
		REP(i, n){
			int x;
			REP(j, 4){
				scanf(" %d ", &x); x--;
				M[i][x]++;
			}
		}
		s--;
		t--;
		if(l == 0){
			if(s == t) printf("1\n");
			else printf("0\n");
		}
		else{
			matrix T = pow(M,l);
			int ans = T[s][t]%MOD;
			if(ans < 0) ans += MOD;
			printf("%d\n", ans);
		}
	}
}
