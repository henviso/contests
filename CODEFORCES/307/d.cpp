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

typedef vector<vector<ull> > matrix;
ull MOD, n, m, l, k;
const int K = 3;
	 
// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K, vector<ull>(K));
    REP(i, K) REP(j, K) REP(z, K)
        C[i][j] = (C[i][j] + A[i][z] * B[z][j]) % MOD;
    return C;
}
	 
// computes A ^ p
matrix pow(matrix A, ull p)
{
    if (p == 1ULL)
        return A;
    if (p % 2ULL)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
 
// returns the N-th term of Fibonacci sequence
ull oneComb(ull N){
	if(N == 0) return 0ULL;
	if(N <= 2) return 1ULL;
	if(N == 3) return 3ULL;
    
    vector<ull> F1(K);
    F1[0] = 3;
    F1[1] = 1;
	F1[2] = 4; 
	
	matrix T(K, vector<ull>(K));
    T[0][0] = T[0][1] = T[0][2] = 1;
    T[1][0] = 1; T[1][1] = T[1][2] = 0; 
    T[2][0] = T[2][1] = 0; T[2][2] = 2;
     
    T = pow(T, N-3);
 
    ull res = 0;
    REP(i, K)
        res = (res + T[0][i] * F1[i]) % MOD;
    return res;
}

ull fastExp(ull base, ull p, ull m){
	if(p == 0ULL) return 1ULL;
	else if(p == 1ULL) return base%m;
	else{
		unsigned long long res = fastExp(base, p/2ULL, m);
		res = (res*res)%m;
		if(p%2ULL == 1ULL) res = (res*base)%m;
		return res;
	}
}

int main(){
	cin >> n >> k >> l >> MOD;
	ull one = oneComb(n);
	ll zero = ((ll) fastExp(2, n, MOD)) - ((ll) one);
	if(zero < 0LL) zero += MOD;
	ull ans = 1ULL;
	int lst = -1;
	REP(i, 64){
		if(k&(1ULL << i)) lst = i+1;
		if(i < l){
			if(k&(1ULL << i)){
				ans = (ans * one)%MOD;
			}
			else ans = (ans * zero)%MOD; 
		}
	}
	if(lst > ((int) l)) ans = 0ULL;
	ans = ans%MOD;
	cout << ans << endl;
}
