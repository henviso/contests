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

int a[1111][1111];

vi hv[1111];
vi hh[1111];
vi sv[1111], sh[1111];

void st_build(vi &st, const vi &A, int vertex, int L, int R) {
  if (L == R)                              // as L == R, either one is fine
    st[vertex] = L;                                      // store the index
  else {   // recursively compute the values in the left and right subtrees
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    st_build(st, A, nL, L              , (L + R) / 2);
    st_build(st, A, nR, (L + R) / 2 + 1, R          );
    int lContent = st[nL]     , rContent = st[nR];
    int lValue   = A[lContent], rValue   = A[rContent];
    st[vertex] = (lValue <= rValue) ? lContent : rContent;
} }

void st_create(vi &st, const vi &A) {       // if original array size is N,
  int len = (int)(2*pow(2.0, floor((log((double)A.size())/log(2.0)) + 1)));
  st.assign(len, 0); // create vector of size `len' and fill it with zeroes
  st_build(st, A, 1, 0, (int)A.size() - 1);              // recursive build
}

int st_rmq(vi &st, const vi &A, int vertex, int L, int R, int i, int j) {
  if (i >  R || j <  L) return -1;   // current segment outside query range
  if (L >= i && R <= j) return st[vertex];            // inside query range

  int p1 = st_rmq(st, A, 2 * vertex    , L              , (L+R) / 2, i, j);
  int p2 = st_rmq(st, A, 2 * vertex + 1, (L+R) / 2 + 1, R          , i, j);

  if (p1 == -1) return p2;     // if we try to access segment outside query
  if (p2 == -1) return p1;                                 // same as above
  return (A[p1] <= A[p2]) ? p1 : p2; }

int st_rmq(vi &st, const vi& A, int i, int j) {     // function overloading
  return st_rmq(st, A, 1, 0, (int)A.size() - 1, i, j); }

int st_update_point(vi &st, vi &A, int node, int b, int e, int idx, int new_value) {
  int i = idx, j = idx;

  if (i > e || j < b)
    return st[node];

  if (b == i && e == j) {
    A[i] = new_value; // update the underlying array
    return st[node] = b; // this index
  }

  int p1, p2;
  p1 = st_update_point(st, A, 2 * node    , b              , (b + e) / 2, idx, new_value);
  p2 = st_update_point(st, A, 2 * node + 1, (b + e) / 2 + 1, e          , idx, new_value);
  
  return st[node] = (A[p1] <= A[p2]) ? p1 : p2;
}

int st_update_point(vi &st, vi &A, int idx, int new_value) {
  return st_update_point(st, A, 1, 0, (int)A.size() - 1, idx, new_value); 
}

int n, m, q;

int main(){
	cin >> n >> m >> q;
	REPP(i, 1, n+1){
		hv[i].assign(m+2, 0);
		REPP(j, 1, m+1){
			cin >> a[i][j];
			if(a[i][j] == 1){
				hv[i][j] = 1;
				if(i-1 > 0) hv[i][j] += hv[i-1][j];
			}
		}
		st_create(sv[i], hv[i]);
	}
	REPP(j, 1, m+1){
		hh[j].assign(n+2, 0);	
		REPP(i, 1, n+1){
			if(a[j][i] == 1){
				hh[j][i] = 1;
				if(i-1 > 0) hh[j][i] += hh[j][i-1];
			}
			//cout << "hv " << j << " " << i << " " << hv[j][i] << endl;
		}
		st_create(sh[j], hh[j]);
	}
	
	int x, R, C;
	REP(i, q){
		cin >> x >> R >> C;
		if(x == 2){
			int ANS = 0;
			for(int i = R; i<=n && hv[i][C] >= i-R+1; i++){ //PROCURANDO ESQUERDA
				int hi = hv[i][C];
				int l = 0, r = C, mid, ans = C;
				while(r-l > 1){
					mid = (l+r)/2;
					if(st_rmq(sv[i], hv[i], mid, r) >= hi){
						ans = mid;
						r = mid;
					} 
					else l = mid;
				}
				cout << "ESQ " << l << " " << r << endl;
				ANS = max(ANS, hi * (l-r+1));
				
				l = C, r = m+1, mid, ans = C;
				while(r-l > 1){
					mid = (l+r)/2;
					if(st_rmq(sv[i], hv[i], l, mid) >= hi){
						ans = mid;
						l = mid;
					} 
					else r = mid;
				}
				ANS = max(ANS, hi * (l-r+1));
			}
			
			for(int j = C; j<=m && hh[j][R] >= j-C+1; j++){ //PROCURANDO PRA CIMA
				int wj = hh[j][R];
				int u = 0, d = R, mid, ans = R;
				while(d-u > 1){
					mid = (d+u)/2;
					if(st_rmq(sh[j], hh[j], mid, d) >= wj){
						ans = mid;
						d = mid;
					} 
					else u = mid;
				}
				ANS = max(ANS, wj * (d-u+1));
				
				u = R, d = n+1, mid, ans = R; //PROCURANDO PRA BAIXO
				while(d-u > 1){
					mid = (d+u)/2;
					if(st_rmq(sh[j], hh[j], u, mid) >= wj){
						ans = mid;
						u = mid;
					} 
					else d = mid;
				}
				ANS = max(ANS, wj * (d-u+1));
				
				//ans = max(ans, hh[R][j] * (u[R][j]+1));
				//cout << " HH " << R << " " << j << " EH " << hh[R][j] << " U EH " << u[R][j] << endl;
				//ans = max(ans, hh[R][j] * (d[R][j]+1));
				//cout << " HH " << R << " " << j << " EH " << hh[R][j] << " D EH " << d[R][j] << endl;
			}
			cout << ANS << endl;
		}
		else{
			if(a[R][C] == 1){
				
				for(int i = R; i<=n && hv[i][C] >= i-R+1; i++){
					//cout << "hv[" << i << "][" << C << "] : " << hv[i][C];
					st_update_point(sv[i], hv[i], C, i-R);
					//cout << "hv[" << i << "][" << C << "] : " << hv[i][C];
				}
				for(int j = C; j<=m && hh[j][R] >= j-C+1; j++) st_update_point(sh[j], hh[j], R, j-C);
				a[R][C] = 0;
			}
			else{
				
				for(int i = R; i<=n && hv[i][C] == i-R; i++) st_update_point(sv[i], hv[i], C, i-R+1);
				for(int j = C; j<=m && hh[j][R] == j-C; j++) st_update_point(sh[j], hh[j], R, j-C+1);
				a[R][C] = 1;
			}
		}
	}
	
}

