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

int n, s, l;
int a[120000];
int lg[120000];

int mx[120000][17];
int mn[120000][17];
int g[120000];
vi st;
vi f;

void processMin(int M[120000][17], int A[120000], int N){
	int i, j;
	for (i = 1; i <= N; i++)
		  M[i][0] = i;
	for (j = 1; 1 << j <= N; j++)
		  for (i = 1; i + (1 << j) - 1 <= N; i++)
			  if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
				  M[i][j] = M[i][j - 1];
			  else
				  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

void processMax(int M[120000][17], int A[120000], int N){
	int i, j;
	for (i = 1; i <= N; i++)
		  M[i][0] = i;
	for (j = 1; 1 << j <= N; j++)
		  for (i = 1; i + (1 << j) - 1 <= N; i++)
			  if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
				  M[i][j] = M[i + (1 << (j - 1))][j - 1];
			  else
				  M[i][j] = M[i][j - 1];
				 
}

int rmqMin(int i, int j){
	int k = lg[j - i + 1];
	return min(a[mn[i][k]], a[mn[j-(1 << k)+1][k]]);
}

int rmqMax(int i, int j){
	int k = lg[j - i + 1];
	return max(a[mx[i][k]], a[mx[j-(1 << k)+1][k]]);
}

void st_build(vi &st, const vi &A, int vertex, int L, int R) {
  if (L == R)                          
    st[vertex] = L;                                    
  else {   
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    st_build(st, A, nL, L              , (L + R) / 2);
    st_build(st, A, nR, (L + R) / 2 + 1, R          );
    int lContent = st[nL]     , rContent = st[nR];
    int lValue   = A[lContent], rValue   = A[rContent];
    st[vertex] = (lValue <= rValue) ? lContent : rContent;
} }

void st_create(vi &st, const vi &A) {      
  int len = (int)(2*pow(2.0, floor((log((double)A.size())/log(2.0)) + 1)));
  st.assign(len, 0); 
  st_build(st, A, 1, 0, (int)A.size() - 1);         
}

int st_rmq(vi &st, const vi &A, int vertex, int L, int R, int i, int j) {
  if (i >  R || j <  L) return -1;   
  if (L >= i && R <= j) return st[vertex];        

  int p1 = st_rmq(st, A, 2 * vertex    , L              , (L+R) / 2, i, j);
  int p2 = st_rmq(st, A, 2 * vertex + 1, (L+R) / 2 + 1, R          , i, j);
                   
  if (p1 == -1) return p2;     
  if (p2 == -1) return p1;     
  return (A[p1] <= A[p2]) ? p1 : p2; }

int st_rmq(vi &st, const vi& A, int i, int j) { 
	if(i > j) return INF;
	return st_rmq(st, A, 1, 0, (int)A.size() - 1, i, j); 
}

int st_update_point(vi &st, vi &A, int node, int b, int e, int idx, int new_value) {
  int i = idx, j = idx;

  if (i > e || j < b)
    return st[node];

  if (b == i && e == j) {
    A[i] = new_value; 
    return st[node] = b; 
  }

  int p1, p2;
  p1 = st_update_point(st, A, 2 * node    , b              , (b + e) / 2, idx, new_value);
  p2 = st_update_point(st, A, 2 * node + 1, (b + e) / 2 + 1, e          , idx, new_value);

  return st[node] = (A[p1] <= A[p2]) ? p1 : p2;
}

int st_update_point(vi &st, vi &A, int idx, int new_value) {
  return st_update_point(st, A, 1, 0, (int)A.size() - 1, idx, new_value); }

int can(int i, int j){
	return ((rmqMax(i, j) - rmqMin(i, j)) <= s);
}

int main(){
	cin >> n >> s >> l;
	REPP(i, 1, n+1){
		cin >> a[i];
	}
	processMax(mx, a, n);
	processMin(mn, a, n);
	
	REPP(i, 1, 100001){
		int r = 0, x = i;
		while(x >>= 1) ++r;	
		lg[i] = r;
	}
	
	REPP(i, 1, n+1){
		int lo = 0, hi = i, mid, res = i;
		while(hi-lo > 1){
			mid = (hi+lo)/2;
			if(can(mid, i)){
				res = mid;
				hi = mid;
			}
			else lo = mid;
		}
		g[i] = res;
	}
	f.assign(n+1, 0);
	st_create(st, f);
	REPP(i, 1, n+1){
		int x = INF, q;
		if(g[i]-1 <= i-l) q = f[st_rmq(st, f, g[i]-1, i-l)];
		else q = INF;
		if(q != INF) x = q + 1;
		st_update_point(st, f, i, x);
	}
	if(f[n] == INF) f[n] = -1;
	cout << f[n] << endl;
}
