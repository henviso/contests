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

int N, W, ans = 0;
int a[1000000], na[1000000];
int b[1000000], nb[1000000];

int fail[1000000];

void buildFail(int *p) {
	int m = W;
	int j = fail[0] = -1;
	for ( int i = 1; i <= m; i++) {
		while (j >= 0 && p[j] != p[i-1]) j = fail[j];
		fail[i] = ++j;
	}
}
void kmp(int *p, int *t) {
	int m = W, n = N;
	buildFail(p);
		for ( int i = 0, k = 0; i < n; i++) {
		while (k >=0 && p[k] != t[i]) k = fail[k];
		if ( ++k >= m ){
			ans++;
			k = fail[k];
		}
	}
}

int main(){
	cin >> N >> W;
	REP(i, N) cin >> a[i];
	REP(i, W) cin >> b[i];
	if(W == 1) cout << N << endl;
	else{
		for(int i = W-1; i>=1; i--) nb[i] = b[i]-b[i-1];
		nb[0] = 0;
		for(int i = N-1; i>=1; i--) na[i] = a[i]-a[i-1];
		na[0] = 0;
		ans = 0;
		N--; W--;
		kmp(nb+1, na+1);
		cout << ans << endl;
	}
}
