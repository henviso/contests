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
typedef pair<ll,ll> pll;
typedef vector< ii > vii;
typedef vector< ll > vll;
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
#define EPS 10e-16

int t, n;
map< int, vi > g;

void st_build(vi &st, const vi &A, int vertex, int L, int R) {
  if (L == R)                          
    st[vertex] = L;                                    
  else {   
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    st_build(st, A, nL, L              , (L + R) / 2);
    st_build(st, A, nR, (L + R) / 2 + 1, R          );
    int lContent = st[nL]     , rContent = st[nR];
    int lValue   = A[lContent], rValue   = A[rContent];
    st[vertex] = (lValue >= rValue) ? lContent : rContent;
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
  return (A[p1] >= A[p2]) ? p1 : p2; }

int st_rmq(vi &st, const vi& A, int i, int j) { 
  return st_rmq(st, A, 1, 0, (int)A.size() - 1, i, j); }

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

  return st[node] = (A[p1] >= A[p2]) ? p1 : p2;
}

int st_update_point(vi &st, vi &A, int idx, int new_value) {
  return st_update_point(st, A, 1, 0, (int)A.size() - 1, idx, new_value); }

int main(){
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> n;
		int x, h;
		REP(i, n){
			cin >> x >> h;
			if(!g.count(x)) g[h] = vector<int>();
			g[h].push_back(x);
		}
		for(map< int, vi >::iterator it = g.begin(); it != g.end(); it++)
			sort(it->second.begin(), it->second.end());
		vi peaks.
		for(map< int, vi >::reverse_iterator it = g.rbegin(); it != g.rend(); it++){
			x = it->first;
			vi v = it->second;
			
			
			cout << "x " << it->first << "\n";
		}
			
		//printf("Case #%d: %.10lf\n", tc, ans);
	}
}

