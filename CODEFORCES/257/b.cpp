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
#define EPS 1e-11
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
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007LL;
const int K = 2;

ll x, y, n;
     
// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K, vector<ll>(K));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
     
// computes A ^ p
matrix pow(matrix A, ll p)
{
    if (p == 1LL)
        return A;
    if (p % 2LL)
        return mul(A, pow(A, p-1LL));
    matrix X = pow(A, p/2LL);
    return mul(X, X);
}
 
// returns the N-th term of Fibonacci sequence
ll fib(ll N)
{
    // create vector F1
    vector<ll> F1(K);
    F1[0] = x;
    F1[1] = y;
     
    // create matrix T
    matrix T(K, vector<ll>(K));
    T[0][0] = 0LL, T[0][1] = 1LL;
    T[1][0] = -1LL, T[1][1] = 1LL;
     
    // raise T to the (N-1)th power
    ll res;
    if(N == 1LL){
		res = F1[0];
	}
	else{
		T = pow(T, N-1);
		// the answer is the first row of T . F1
		res = 0LL;
		REP(i, K) res = (res + T[0][i] * F1[i]) % MOD;
	}
	if(res < 0LL) res += MOD;
    return res;
}

int main(){
    cin >> x >> y >> n; 
    cout << fib(n) << endl;
}
