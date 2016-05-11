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
 
int t;
ll n, k;
ll K[1000100];
 
ll x, y, d;

//inv modular de a mod b = m eh o x
void extendedEuclid(int a, int b){
	if(b == 0){ x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a%b);
	ll x1 = y;
	ll y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

ll invMult(ll a, ll m){
	extendedEuclid(a, m);
	x = x%m;
	if(x < 0) x += m;
	return x;
}
 
ll calc(ll a, ll b){
	if(b < a) swap(a, b);
	ll div = invMult((k-1), MOD);
	ll X = (((K[n+1] - 1LL)*div)%MOD) - 2LL - (((K[b]-1LL)*div)%MOD);
	if(X < MOD) x += MOD;
	ll res = X - ((X*invMult(K[b], MOD))%MOD) - ((X*invMult(K[a], MOD))%MOD);
	if(res<0LL) res += MOD;
	return res;
}
 
int main(){
	scanf(" %d ", &t);
	while(t--){ 
		scanf(" %lld %lld ", &n, &k);
		K[0] = 1LL;
		REPP(i, 1, n+1) K[i] = (K[i-1]*k)%MOD;
		ll ans = 0LL;
		for(ll i = 1LL; i<=n; i++){
			ll sum = 0LL;
			for(ll j = 1LL; j<i; j++){
				//ll x = (((K[i] * (K[j] - K[j-i]))%MOD)*(K[l]-K[l-j]-K[l-i]))%MOD;
				//if(j < l) x *= (x*2LL)%MOD;
				//cout << "i:" << i << " j:" << j << " l:" << l << " -----> " << calc(i, j, l) << endl;
				ll X = (i >= j)? (K[j] * (K[i]-K[i-j]))%MOD : (K[i] * (K[j]-K[j-i]))%MOD;
				if(X < 0LL) X += MOD;
				ans = (ans + (X*calc(i, j))%MOD)%MOD; 
			}
		}
		while(ans < 0) ans += MOD;
		printf("%lld\n", ans);
	}
}
