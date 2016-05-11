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

#define SIEVE_MAX 10000000
bitset<SIEVE_MAX+1> _prime; 
vi primes;

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.pb(2);
	for(ll i = 4; i<SIEVE_MAX; i+=2) _prime[i] = 0;
	for(ll i = 3; i<SIEVE_MAX; i+=2){
		if(_prime[i]){ 
			for(ll j = i*i; j<SIEVE_MAX; j+=2*i) _prime[j] = 0;
			primes.push_back((int) i);
		}
	}
}

bool isPrime(ll N){
	if(N <= SIEVE_MAX) return _prime[N];
	for(int i = 0; i<(int) primes.size(); i++){
		if(N%primes[i] == 0) return false;
	}
	return true;
}

ll EulerPhi(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = N;
	while(N != 1 && (PF * PF <= N)){
		if(N%PF == 0) ans -= ans / PF;
		while(N%PF == 0) N /= PF;
		PF = primes[++PF_idx];
	}
	if(N != 1) ans -= ans/N;
	return ans;
}

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

ll fastExp(ll base, ll p, ll m){
	if(p == 0LL) return 1LL;
	else if(p == 1LL) return base%m;
	else{
		unsigned long long res = fastExp(base, p/2LL, m);
		res = (res*res)%m;
		if(p%2LL == 1LL) res = (res*base)%m;
		return res;
	}
}

int main()
{
	sieve();
	ll c, n, e;
	while (scanf("%lld %lld %lld", &n, &e, &c) != EOF) {
		ll tot = EulerPhi(n);
		ll d = invMult(e, tot);
		ll m = fastExp(c, d, n);
		printf("%lld\n", m);
	}
}
