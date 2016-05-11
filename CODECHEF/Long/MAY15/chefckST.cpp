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
#define MOD 1000000007
//__builtin_popcount(m)
//scanf(" %d ", &t);

ll sum = 0LL, prod = 1LL;
ii queries[10000100];
ll n, k, q;
ll a, b, c, d, e, f, r, s, t, m;
ll L1, La, Lc, Lm, D1, Da, Dc, Dm;
ll pd[2][10000100];

void solve(){
	int act = 1, lst = 0, p = 0;
	int block;
	while(queries[p].first == 1){
		sum += pd[0][queries[p].second];
		prod = (prod*pd[0][queries[p].second])%MOD;
		p++;
	}
	for(int j = 1; (1 << j) <= n; j++){
		int k = (1 << (j-1)), nxt = (1 << (j+1));
		REPP(i, 1, n+1){
			if(i+k <= n) pd[act][i] = min(pd[lst][i], pd[lst][i+k]);
		}
		while(nxt > queries[p].first){
			ll x = min(pd[act][queries[p].second], pd[act][queries[p].first + queries[p].second-(1<<j)]);
			sum += x;
			prod = (prod*x)%MOD;
			p++;
		}
		swap(act, lst);
	}
}

int main(){
    scanf(" %lld %lld %lld ", &n, &k, &q);
    scanf(" %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld ", &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &pd[0][1]);
    scanf(" %lld %lld %lld %lld %lld %lld %lld %lld ", &L1, &La, &Lc, &Lm, &D1, &Da, &Dc, &Dm);
    ll p = t;
    REPP(x, 2, n+1){
		p = (p*t)%s;
		if(p <= r) pd[0][x] = (pd[0][x-1]*((a*pd[0][x-1] + b)%m)+c)%m; 
		else pd[0][x] = (pd[0][x-1]*((d*pd[0][x-1] + e)%m)+f)%m; 
	}
	ll L, R;
	k--;
	REPP(i, 1, q+1){
		L1 = (La * L1 + Lc)%Lm;
		D1 = (Da * D1 + Dc)%Dm; 
		L = L1 + 1;
		R = min(L + k + D1, n);
		queries[i-1] = (L<=R)? ii(R-L+1, L) : ii(L-R+1, R);
	}
	queries[q++] = ii(INF, INF);
	sort(queries, queries+q);
	solve();
	printf("%lld %lld\n", sum, prod);
}
