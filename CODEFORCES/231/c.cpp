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

#define SIEVE_MAX 10000000
#define MOD 1000000007LL

ll x, y, d;

bitset<SIEVE_MAX+1> _prime; 
vi primes;

int n;
ll a[1000];
ll f[100000];

//inv modular de a mod b = m é o x
void extendedEuclid(ll a, ll b){
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

vi primeFactors(ll N) {
	vi factors;     //TROCAR PRA vll SE O NUMERO FOR > QUE INT
	ll PF_idx = 0, PF = primes[PF_idx];
	while(N > 1 && (PF*PF <= N)){
		while(N%PF == 0){ N /= PF; factors.push_back((int) PF); }
		PF = primes[++PF_idx];
	}
	if(N > 1) factors.push_back((int) N);
	return factors; 
}

ll bin(int c, int p){
	ll a = f[c], b = (f[c-p]*f[p])%MOD;
	return ((a*invMult(b, MOD))%MOD);
}

int main(){
	ios::sync_with_stdio(false);
	sieve();
	f[0] = f[1] = 1LL;
	REPP(i, 2, 100000) f[i] = (f[i-1]*((ll) i))%MOD;
	
	cin >> n;
	vi pf;
	map<int, int> cnt;
	REP(i, n){
		cin >> a[i];
		pf = primeFactors(a[i]);
		REP(j, pf.size()) cnt[pf[j]]++;
	}
	ll ans = 1LL;
	for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
		int k = it->second;
		ans *= bin(n+k-1, k);
		ans = ans%MOD;
	}
	cout << ans << endl;
}
	

