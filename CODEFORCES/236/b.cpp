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
bitset<SIEVE_MAX+1> _prime; 
vi primes;

int n, m;
int a[10000];
set<int> b;

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

int f(int x){
	vi pf = primeFactors(x);
	int ans = 0;
	REP(i, pf.size()){
		if(b.count(pf[i])) ans--;
		else ans++;
	}
	return ans;
}

int mdc(int a, int b) {
  if(a<0) a = -a;
  if(b<0) b = -b;

  if(b == 0)
    return a;
  else
    return mdc(b, a%b);
}

int main(){
	sieve();
	ios::sync_with_stdio(false);
	cin >> n >> m;
	REP(i, n) cin >> a[i];
	int aux;
	REP(i, m){
		cin >> aux;
		b.insert(aux);
	}
	
	while(1){
		int lst = 1, lstg = 10, i = 1, g = a[0], fg = f(a[0]);
		
		//cout << " LST " << lst << " G " << g << " FG " << fg << endl;
		
		while(i<n && fg < 0){
			lst = g;
			lstg = fg;
			g = mdc(g, a[i]);	
			fg = f(g);
			i++;
		}
		
		//cout << " I " << i << " FG " << fg << " G " << g << " LST " << lst << endl;
		
		if(fg < 0) REP(j, i) a[j] /= g;
		else{
			if(lstg < 0) REP(j, i-1) a[j] /= lst;
			else break;
		} 
	}
	int ans = 0;
	REP(i, n){
		//cout << a[i] << " " << f(a[i]) << endl;
		ans += f(a[i]);
	}
	cout << ans << endl;
	
}

